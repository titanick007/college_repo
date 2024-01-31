#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
struct dataPack{
    char c;
    int num;
    float decimal_num;
};

int main() {
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Client failure\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);

    int connectStatus = connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    if (connectStatus == -1) {
        printf("Connection failed\n");
        exit(EXIT_FAILURE);
    }

    struct dataPack msg_server;
    printf("Enter a character: ");
    scanf(" %c",&msg_server.c);
    printf("Enter a integer: ");
    scanf("%d",&msg_server.num);
    printf("Enter a decimal number: ");
    scanf("%f",&msg_server.decimal_num);


    
    int bytes_sent = send(client_socket, &msg_server, sizeof(msg_server), 0);
    if (bytes_sent == -1) {
        printf("Message not sent\n");
        exit(EXIT_FAILURE);
    }
    printf("\nmessage sent to server\n\n");
    

    close(client_socket);

    return 0;
}
