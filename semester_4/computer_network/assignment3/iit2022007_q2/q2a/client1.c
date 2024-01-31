#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>


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


    char server_msg;
    struct sockaddr_storage server_address;
    socklen_t server_address_len=sizeof(server_address);

    char message;
    printf("\nEnter alphabet for server: ");
    scanf(" %c", &message);

    // Clear the input buffer
    while (getchar() != '\n');
   

    int msg_sent = sendto(client_socket, &message, sizeof(message), 0,
                           (struct sockaddr *)&my_address, sizeof(my_address));
    if (msg_sent == -1) {
        printf("Message not sent\n");
        exit(EXIT_FAILURE);
    }
    printf("\nmessage sent to server\n\n");


    close(client_socket);

    return 0;
}
