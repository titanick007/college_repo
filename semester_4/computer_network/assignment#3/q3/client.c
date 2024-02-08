#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// ./a.out [server address] [port number] [filename.txt]
int main(int argc, char* argv[]) {
    FILE *fptr1;
    fptr1 = fopen("receive.txt", "w+");
    if (fptr1 == NULL) {
        printf("Error in creating file\n");
        exit(EXIT_FAILURE);
    }

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Client failure\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_address.sin_addr);

    int connectStatus = connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    if (connectStatus == -1) {
        printf("Connection failed\n");
        exit(EXIT_FAILURE);
    }

    char *message = argv[3]; // Sending file name
    int bytes_sent = send(client_socket, message, strlen(message), 0); // Corrected sizeof to strlen
    if (bytes_sent == -1) {
        printf("Message not sent\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for file_contents
    char file_contents[1024]; // Adjust the size as needed
    int bytes_received = recv(client_socket, file_contents, sizeof(file_contents), 0); // Corrected size parameter
    if (bytes_received == -1) {
        printf("Message not received\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fptr1, "%.*s", bytes_received, file_contents); // Write received data to file

    fclose(fptr1);
    close(client_socket);

    return 0;
}
