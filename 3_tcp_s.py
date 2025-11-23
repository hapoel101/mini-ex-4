# 3_tcp_s.py

# importing the socket module
import socket
# creating a TCP socket
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# defining server IP.
server_ip = ''
# defining server port.
server_port = 12345
# binding the socket to the IP and port.
server.bind((server_ip, server_port))
# listening for incoming connections.
server.listen(5)

# accepting and handling client connections in a loop.
while True:
    # accepting a client connection.
    client_socket, client_address = server.accept()
    # printing the client address.
    print('Connection from: ', client_address)
    # receiving data from the client.
    data = client_socket.recv(1024)
    # processing data until the client disconnects.
    while not data.decode('utf-8') == '':
        # printing the received data.
        print('Received: ', data.decode('utf-8'))
        # sending back the uppercase version of the received data.
        client_socket.send(data.upper())
        # receiving the next data from the client.
        data = client_socket.recv(1024)

    # client has disconnected.
    print('Client disconnected')
    # closing the client socket.
    client_socket.close()