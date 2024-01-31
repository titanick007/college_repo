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
    int client_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (client_socket == -1) {
        printf("Client failure\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in my_address;
    memset((void *) &my_address, 0, sizeof(my_address));
    my_address.sin_family = AF_INET;
    my_address.sin_port = htons(8081);
    inet_pton(AF_INET, "127.0.0.1", &my_address.sin_addr);
    
    if (bind(client_socket, (struct sockaddr *)&my_address, sizeof(my_address)) == -1) {
        printf("Bind failed\n");
        exit(EXIT_FAILURE);
    }


    struct dataPack response_server;
    struct sockaddr_storage server_address;
    socklen_t server_address_len=sizeof(server_address);
    int msg_receive = recvfrom(client_socket, &response_server, sizeof(response_server), 0,
                               (struct sockaddr *)&server_address, &server_address_len);
    if (msg_receive == -1) {
        printf("Message not received\n");
        exit(EXIT_FAILURE);
    }
    printf("\n\nReceived message from server:\n", response_server);

    printf("\nMessage from server\n");
    printf("char : %c\n",response_server.c);
    printf("int : %d\n",response_server.num);
    printf("float : %1f\n",response_server.decimal_num);

    
    

    close(client_socket);

    return 0;
}
