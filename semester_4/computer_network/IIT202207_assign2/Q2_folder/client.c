#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int client_socket;
    struct sockaddr_in server_address;

    // socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    // connect
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(12345);
    connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address));

    // send
    char* message = "Hello, server! How are you?";
    send(client_socket, message, strlen(message), 0);

    // recv
    char buffer[1024];
    recv(client_socket, buffer, sizeof(buffer), 0);
    printf("Received from server: %s\n", buffer);

    // close
    close(client_socket);

    return 0;
}
