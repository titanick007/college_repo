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

    while(1){
        char buffer[1024];
    int msg_receive = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (msg_receive == -1) {
        printf("Message not received\n");
        exit(EXIT_FAILURE);
    }
    buffer[msg_receive] = '\0'; // Null-terminate the received data
    printf("Received message from client: %s\n", buffer);

        char message[1024];
    printf("Enter message for client: ");
    fgets(message, sizeof(message), stdin);

    int msg_sent = send(client_socket, message, strlen(message), 0);
    if (msg_sent == -1) {
        printf("Message not sent\n");
        exit(EXIT_FAILURE);
    }
    printf("Message sent to client\n");
    }
        

    close(client_socket);
    close(server_socket);

    return 0;
}
