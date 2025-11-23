# 3_tcp_c.py

# importing the socket module
import socket

# creating a TCP socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# defining destination IP.
dest_ip = '127.0.0.1'
# defining destination port.
dest_port = 12345
# connecting to the server.
s.connect((dest_ip, dest_port))

# sending and receiving messages in a loop.
msg_number_input = input("Number of messages to send: ")
msg_number = int(msg_number_input)
msg = input("Message to send: ")
# loop until the user types 'quit'.
while not msg == 'quit' and msg_number > 0:
    msg_number = msg_number - 1
    # sending the message to the server.
    s.send(bytes(msg, 'utf-8'))
    # receiving the response from the server.
    data = s.recv(4096)
    # printing the response.
    print("Server sent: ", data.decode('utf-8'))
    # getting the next message from the user.
    if msg_number > 0:  
        msg = input("Message to send: ")

msg = 'quit'
s.send(bytes(msg, 'utf-8'))
# closing the socket
s.close()