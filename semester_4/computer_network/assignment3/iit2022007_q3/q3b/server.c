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

    int client_socket1 = accept(server_socket, NULL, NULL);
    if (client_socket1 == -1) {
        printf("Accept failed\n");
        exit(EXIT_FAILURE);
    }

    struct dataPack response_client1;
    int msg_receive = recv(client_socket1, &response_client1, sizeof(response_client1), 0);
    if (msg_receive == -1) {
        printf("\nMessage not received\n");
        exit(EXIT_FAILURE);
    }
    printf("\nReceived message from client 1: \n", response_client1);

    printf("\nMessage from client 1\n");
    printf("char : %c\n",response_client1.c);
    printf("int : %d\n",response_client1.num);
    printf("float : %1f\n\n",response_client1.decimal_num);
    //Making changes to data from client 1
    printf("Enter a new character: ");
    scanf(" %c",&response_client1.c);
    printf("Enter a new integer: ");
    scanf("%d",&response_client1.num);
    printf("Enter a new decimal number: ");
    scanf("%f",&response_client1.decimal_num);


    close(client_socket1);
    
    

    int client_socket2 = accept(server_socket, NULL, NULL);
    if (client_socket2 == -1) {
        printf("Accept failed\n");
        exit(EXIT_FAILURE);
    }

    int new_msg_sent = send(client_socket2, &response_client1, sizeof(response_client1), 0);
    if (new_msg_sent == -1) {
        printf("Message not sent\n");
        exit(EXIT_FAILURE);
    }
    printf("\nMessage sent to client 2\n");

    close(server_socket);

    return 0;
}
