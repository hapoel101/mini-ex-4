#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>


using namespace std;

int main() {

    // defining server port.
    const int server_port = 5555;

    // creating socket and checking for errors.
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }

    // defining server address struct.
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    // binding socket to the specified IP and port.
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }

    // listening for connections.
    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
    }

    // accepting a client connection.
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    int client_sock = accept(sock,  (struct sockaddr *) &client_sin,  &addr_len);

    // checking for errors while accepting client.
    if (client_sock < 0) {
        perror("error accepting client");
    }

    // receiving data from client.
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
    // connection is closed
    }
    else if (read_bytes < 0) {
    // error
    }
    else {
        cout << buffer;
    }

    // sending data back to client.
    int sent_bytes = send(client_sock, buffer, read_bytes, 0);

    // checking for errors while sending data to client.
    if (sent_bytes < 0) {
        perror("error sending to client");
    }

    // closing client and server sockets.
    close(client_sock);
    close(sock);


    return 0;
}