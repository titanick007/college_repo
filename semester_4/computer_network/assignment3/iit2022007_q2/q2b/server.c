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
    int server_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_socket == -1) {
        printf("Serve failure\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    memset((void *) &server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY; // Use INADDR_ANY to bind to all available interfaces
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        printf("Bind failed\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_storage client_address1;
    socklen_t client_address1_len = sizeof(client_address1);

    struct dataPack response_client1;
    int msg_receive = recvfrom(server_socket, &response_client1, sizeof(response_client1), 0,
                               (struct sockaddr *)&client_address1,&client_address1_len);
    if (msg_receive == -1) {
        printf("Message not received\n");
        exit(EXIT_FAILURE);
    }
    printf("\nReceived message from client 1:\n", response_client1);

    printf("\nMessage from client 1\n");
    printf("char : %c\n",response_client1.c);
    printf("int : %d\n",response_client1.num);
    printf("float : %1f\n",response_client1.decimal_num);
    //Making changes to data from client 1
    printf("Enter a new character: ");
    scanf(" %c",&response_client1.c);
    printf("Enter a new integer: ");
    scanf("%d",&response_client1.num);
    printf("Enter a new decimal number: ");
    scanf("%f",&response_client1.decimal_num);

    memset((void *) &server_address, 0, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8081);
    server_address.sin_addr.s_addr = INADDR_ANY; // Use INADDR_ANY to bind to all available interfaces
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);
    

    int new_msg_sent = sendto(server_socket, &response_client1, sizeof(response_client1), 0, (struct sockaddr*)&server_address,sizeof(server_address));
    if (new_msg_sent == -1) {
        printf("Failed to send message to client 2\n");
        exit(EXIT_FAILURE);
    }
    printf("\nMessage sent to client 2\n");

    close(server_socket);

    return 0;
}
