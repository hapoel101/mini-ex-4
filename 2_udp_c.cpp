#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

using namespace std;

int main() {

    // defining server IP address and port.

    // Note: The IP address "127.0.666.1" is intentionally invalid for testing purposes.
    const char* ip_address = "127.0.666.1";
    const int port_no = 5556;

    // creating a UDP socket.
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }

    // defining server address struct.
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);

    // sending data to the server.
    char data[] = "hello";
    int data_len = sizeof(data);

    // sending data to the server.
    int sent_bytes = sendto(sock, data, data_len, 0, (struct sockaddr *) &sin, sizeof(sin));
    if (sent_bytes < 0) {
        perror("error writing to socket");
    }

    // receiving data from server.
    struct sockaddr_in from;
    unsigned int from_len = sizeof(struct sockaddr_in);
    char buffer[4096];
    int bytes = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *) &from, &from_len);

    // checking for errors in receiving data
    if (bytes < 0) {
        perror("error reading from socket");
    }

    // printing the received data.
    cout << "The server sent: " << buffer << endl;
    // closing the socket.
    close(sock);

    return 0;
}