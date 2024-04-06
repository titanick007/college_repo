#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void handle_client(int client_socket, char *client_host) {

    // Receive file name from client
    char file_name[256];
    long bytes_received = recv(client_socket, file_name, sizeof(file_name), 0);
    if (bytes_received == -1) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }
    file_name[bytes_received] = '\0';

    // Open the requested file
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("File open failed");
        exit(EXIT_FAILURE);
    }

    // Send file contents to client
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        if (send(client_socket, buffer, bytes_read, 0) == -1) {
            perror("Send failed");
            exit(EXIT_FAILURE);
        }
    }

    printf("File sent successfully to %s\n\n\n", client_host);

    // Close client socket and file
    fclose(file);
    close(client_socket);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [service_name]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Resolve service name to port number
    struct servent *service_entry = getservbyname(argv[1], "tcp");
    if (service_entry == NULL) {
        perror("getservbyname failed");
        exit(EXIT_FAILURE);
    }
    int port_number = ntohs(service_entry->s_port);

    // Create socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    int enable_reuse = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &enable_reuse, sizeof(enable_reuse)) == -1) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Bind to address and port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port_number);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n\n\n", port_number);

    // Main server loop
    while (1) {
        // Accept connections
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket == -1) {
            perror("Accept failed");
            continue;
        }

        // Resolve client's host name
        struct hostent *client_host_entry = gethostbyaddr((const char *)&client_addr.sin_addr.s_addr, sizeof(client_addr.sin_addr.s_addr), AF_INET);
        if (client_host_entry == NULL) {
            perror("Error resolving client host");
        } else {
            printf("Request received from hostname : %s\n",client_host_entry->h_name);
        }

        // Fork a new process to handle the client
        pid_t pid = fork();
        if (pid == -1) {
            perror("Fork failed");
            close(client_socket);
            continue;
        } else if (pid == 0) { // Child process
            close(server_socket); // Close the listening socket in child process
            handle_client(client_socket, client_host_entry->h_name); // Handle client communication
            exit(EXIT_SUCCESS);
        } else { // Parent process
            close(client_socket); // Close client socket in parent process
            // Clean up terminated child processes to avoid zombie processes
            while (waitpid(-1, NULL, WNOHANG) > 0);
        }
    }

    // Close server socket
    close(server_socket);

    return 0;
}
