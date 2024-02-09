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

    Request client_request;
    int msg_receive = recv(client_socket, &client_request, sizeof(client_request), 0);
    if (msg_receive == -1) {
        printf("Message not received\n");
        exit(EXIT_FAILURE);
    }    
    printf("Received request from client.\n");

    FILE *file_pointer;
    char filename[] = "database.txt"; // Name of the file
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
    Reply server_respone;
    server_respone.etx=0b00000011;
    if(client_request.code==0b00001001){
        while (fscanf(file_pointer, "%d %s", &num, message) != EOF) {
            // Check if the current number matches the input number
            if (num == atoi(client_request.data)) {
                strcpy(server_respone.data,message);
                flag=1;
                break; // Exit the loop once a match is found
            }
        }
    }
    else if(client_request.code==0b00000001){
         while (fscanf(file_pointer, "%d %s", &num, message) != EOF) {
            // Check if the current number matches the input number
            if (strcmp(message, client_request.data) == 0) {
                sprintf(server_respone.data, "%d", num);               
                flag=1;
                break; // Exit the loop once a match is found
            }
        }
    }


    if(flag==0){
        strcpy(server_respone.data, "Not found in database");
    }
    int msg_sent = send(client_socket, &server_respone, sizeof(server_respone), 0);
    if (msg_sent == -1) {
        printf("Message not sent\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Reply sent to client\n");

    fclose(file_pointer);
        

    close(client_socket);
    close(server_socket);

    return 0;
}
