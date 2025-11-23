# importing necessary modules
from socket import socket, AF_INET, SOCK_DGRAM

# creating a UDP socket
s = socket(AF_INET, SOCK_DGRAM)

# defining destination IP and port
dst_ip = '127.0.0.1'
dst_port = 11111

# sending a message to the server
s.sendto(b'Hello', (dst_ip,dst_port))

# receiving a response from the server
data, sender_info = s.recvfrom(2048)
# printing the received data and sender information
print(data.decode('utf-8'))
# printing the sender's address
print(sender_info)

# closing the socket
s.close()
