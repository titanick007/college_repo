#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Serve failure\n");
        exit(EXIT_FAILURE);
    }

    int enable_reuse = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &enable_reuse, sizeof(enable_reuse)) == -1) {
        printf("setsockopt failed\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        printf("Bind failed\n");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) == -1) {
        printf("Listen failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port number 8080\n");

    int client_socket = accept(server_socket, NULL, NULL);
    if (client_socket == -1) {
        printf("Accept failed\n");
        exit(EXIT_FAILURE);
    } 

        int buffer;
    int msg_receive = recv(client_socket, &buffer, sizeof(buffer), 0);
    if (msg_receive == -1) {
        printf("Message not received\n");
        exit(EXIT_FAILURE);
    }    
    printf("Received message from client: %d\n", buffer);

    FILE *file_pointer;
    char filename[] = "file.txt"; // Name of the file
    int num;
    char message[100]; // Name corresponding to the input number

    // Open the file in read mode
    file_pointer = fopen(filename, "r");

    // Check if the file opened successfully
    if (file_pointer == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    int flag=0;
    while (fscanf(file_pointer, "%d %s", &num, message) != EOF) {
        // Check if the current number matches the input number
        if (num == buffer) {
            printf("Name: %s\n", message);
            flag=1;
            break; // Exit the loop once a match is found
        }
    }
    if(flag==0){
        char problem='0';
        int msg_sent = send(client_socket, &problem, sizeof(problem), 0);
        if (msg_sent == -1) {
            printf("Message not sent\n");
            exit(EXIT_FAILURE);
        }
    }
    else{
        int msg_sent = send(client_socket, message, strlen(message), 0);
        if (msg_sent == -1) {
            printf("Message not sent\n");
            exit(EXIT_FAILURE);
        }
    }
    
    printf("Message sent to client\n");
        

    close(client_socket);
    close(server_socket);

    return 0;
}
