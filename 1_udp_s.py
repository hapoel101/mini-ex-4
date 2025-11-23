# importing necessary modules
from socket import socket, AF_INET, SOCK_DGRAM

# creating a UDP socket
s = socket(AF_INET, SOCK_DGRAM)

# defining source IP
src_ip = ''
# defining source port
src_port = 11111
# binding the socket
s.bind((src_ip, src_port))
# continuously listening for incoming messages
while True:
    # receiving data from clients
    data, sender_info = s.recvfrom(2048)
    # printing the received data and sender information
    print(data.decode('utf-8'))
    # printing the sender's address
    print(sender_info)

    # sending back the uppercase version of the received data
    s.sendto((data.decode('utf-8') + "->" + data.decode('utf-8').upper()).encode('utf-8'), sender_info)
