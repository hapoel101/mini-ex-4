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
    const char* ip_address = "127.0.0.1";
    const int port_no = 5555;

    // creating socket and checking for errors.
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }

    // defining server address struct.
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);

    // connecting to the server.
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }

    // sending data to the server.
    char data_addr[] = "Im a message. Please send me back!\n";
    int data_len = strlen(data_addr);
    int sent_bytes = send(sock, data_addr, data_len, 0);

    if (sent_bytes < 0) {
    // error
    }

    // receiving data from server.
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
    // connection is closed
    }
    else if (read_bytes < 0) {
    // error
    }
    else {
        cout << buffer;
    }

    // closing the socket.
    close(sock);


    return 0;
}