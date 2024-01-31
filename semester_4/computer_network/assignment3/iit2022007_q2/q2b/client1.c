#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

struct dataPack{
    char c;
    int num;
    float decimal_num;
};


int main() {
    int client_socket = socket(AF_INET, SOCK_DGRAM, 0); // Use SOCK_DGRAM for UDP
    if (client_socket == -1) {
        printf("Client failure\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in my_address;
    memset((void *) &my_address, 0, sizeof(my_address));
    my_address.sin_family = AF_INET;
    my_address.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &my_address.sin_addr);

    struct sockaddr_storage server_address;
    socklen_t server_address_len=sizeof(server_address);

    struct dataPack msg_server;
    printf("Enter a character: ");
    scanf(" %c",&msg_server.c);
    printf("Enter a integer: ");
    scanf("%d",&msg_server.num);
    printf("Enter a decimal number: ");
    scanf("%f",&msg_server.decimal_num);
   

    int msg_sent = sendto(client_socket, &msg_server, sizeof(msg_server), 0,
                           (struct sockaddr *)&my_address, sizeof(my_address));
    if (msg_sent == -1) {
        printf("Message not sent\n");
        exit(EXIT_FAILURE);
    }
    printf("\nmessage sent to server\n\n");


    close(client_socket);

    return 0;
}
