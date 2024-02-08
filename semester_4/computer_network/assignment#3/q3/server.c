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

    char*buffer;
    int msg_receive = recv(client_socket, &buffer, sizeof(buffer), 0);
    if (msg_receive == -1) {
        printf("Message not received\n");
        exit(EXIT_FAILURE);
    }

    FILE*fptr;
    fptr=fopen(buffer,"r");
    if(fptr==NULL){
        printf("Couldn't open file\n");
        exit(EXIT_FAILURE);
    }

     // Determine the size of the file.
    fseek(fptr, 0, SEEK_END);
    long fsize = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    // Allocate a char array of the same size as the file.
    char *file_contents = malloc(fsize + 1);
    if (file_contents == NULL) {
      printf("Error allocating memory.\n");
      fclose(fptr);
      return 1;
    }

    // Read the contents of the file into the char array.
    fread(file_contents, fsize, 1, fptr);
    file_contents[fsize] = '\0'; // Add a null terminator to the end of the string.


    int msg_sent=send(client_socket,file_contents,sizeof(file_contents),0);
    if (msg_sent == -1) {
        printf("Message not sent\n");
        exit(EXIT_FAILURE);
    }

        

    close(client_socket);
    close(server_socket);

    return 0;
}
