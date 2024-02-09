#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define MAX_SIZE 256


//00001001 is number request    
//00000001 is name request
typedef struct{
    char code;      //for name or number request
    char data[MAX_SIZE];
    char etx;
}Request;
typedef struct{
    char data[MAX_SIZE];
    char etx;
}Reply;

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

        Request client_request;
        char temp;
        printf("Enter type of request:\n s for name and d number\n");
        scanf(" %c",&temp);
        if(temp=='s'){
            client_request.code=0b00000001;   //Name request
            printf("Enter name: ");
            scanf(" %s",&client_request.data);
        }
        else if(temp=='d'){
            client_request.code=0b00001001;   //Number request
            printf("Enter number: ");
            scanf(" %s",&client_request.data);
        }
        client_request.etx=0b00000011;

        int bytes_sent = send(client_socket, &client_request,sizeof(client_request), 0);
        if (bytes_sent == -1) {
            printf("Message not sent\n");
            exit(EXIT_FAILURE);
        }

    
        Reply server_response;
        int bytes_receive = recv(client_socket, &server_response, sizeof(server_response), 0);
        if (bytes_receive == -1) {
            printf("Message not received\n");
            exit(EXIT_FAILURE);
        }
        server_response.data[bytes_receive] = '\0'; // Null-terminate the received data
        printf("Reply received: %s\n",server_response.data);

    close(client_socket);

    return 0;
}
