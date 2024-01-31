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

    struct sockaddr_in my_address;
    my_address.sin_family = AF_INET;
    my_address.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &my_address.sin_addr);

    int connectStatus = connect(client_socket, (struct sockaddr*)&my_address, sizeof(my_address));
    if (connectStatus == -1) {
        printf("Connection failed\n");
        exit(EXIT_FAILURE);
    }
    
    
    struct dataPack buffer;
    int bytes_receive = recv(client_socket, &buffer, sizeof(buffer), 0);
    if (bytes_receive == -1) {
        printf("Message not received\n");
        exit(EXIT_FAILURE);
    }
    printf("\n\nReceived message from server:\n", buffer);
    printf("char : %c\n",buffer.c);
    printf("int : %d\n",buffer.num);
    printf("float : %1f\n",buffer.decimal_num);

    close(client_socket);

    return 0;
}
