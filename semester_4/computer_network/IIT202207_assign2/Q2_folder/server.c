#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);

    // socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // bind
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(12345);
    bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));

    // listen
    listen(server_socket, 5);
    printf("Server listening on port 12345\n");

    // accept
    client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_length);
    printf("Accepted connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    // recv
    char buffer[1024];
    recv(client_socket, buffer, sizeof(buffer), 0);
    printf("Received data: %s\n", buffer);

    // send
    char* message = "Hello, client! Thanks for connecting.";
    send(client_socket, message, strlen(message), 0);

    // close
    close(client_socket);
    close(server_socket);

    return 0;
}
