
# Riley Huston      (190954880)
# Samson Goodenough (190723380)

# Import socket module
from socket import * 
import sys # In order to terminate the program
import struct

serverName = 'localhost'
#serverName = '10.84.88.53'
# Assign a port number
serverPort = 12000

# Bind the socket to server address and server port
clientSocket = socket(AF_INET, SOCK_DGRAM)
clientSocket.settimeout(0.5)

print('-'*40,"PHASE A",'-'*40)

# Declare Packet Variables
entity = 1
pcode = 0
data = "Hello World!!!"
data = data.encode() + bytearray(4-len(data)%4)
data_length = len(data)

# Create Packet
ClientMessage = struct.pack(f'!IHH{data_length}s',data_length, pcode, entity, data)

# Send Packet to server
clientSocket.sendto( ClientMessage, (serverName, serverPort))

# Recieve from server
ServerMessage, serverAddress = clientSocket.recvfrom(2048)
print('SERVER PACKET: ', ServerMessage)
_, _, _, repeat, udp_port, len, codeA  = struct.unpack('!IHHIIHH',ServerMessage)
print('SERVER UNPACKET: ', struct.unpack('!IHHIIHH',ServerMessage))

 # Phase B
print('-'*40,"PHASE B",'-'*40)
pcode = codeA
print(repeat, len)
packet_id = 0
while packet_id < repeat:
    try:
        data = bytearray(len+len%4)
        data_length = len+len%4 + 4
        ClientMessage = struct.pack(f'!IHHI{len+len%4}s',data_length, pcode, entity, packet_id, data)
        clientSocket.sendto(ClientMessage, (serverName, udp_port))
        ServerAck, serverAddress = clientSocket.recvfrom(2048)
        print("SERVER ACK: ", struct.unpack('!IHHI', ServerAck))
        packet_id += 1
    except:
        print("AAAA TIME TIME WTF ARE YOU DOING AAAAAA")

clientSocket.close()

# Packet: 32 bits total
# Data_length: 4 bits
# pcode: 2 bits
# Entity: 2 bits
# Data: any size divisible by 4 and less than 24 bits

