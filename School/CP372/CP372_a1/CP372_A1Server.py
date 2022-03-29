
# Riley Huston      (190954880)
# Samson Goodenough (190723380

# Import socket module
from socket import * 
import sys # In order to terminate the program
import struct
import random

# Assign a port number
serverPort = 12000
serverSocket = socket(AF_INET, SOCK_DGRAM)

# Bind the socket to server address and server port
serverSocket.bind(("", serverPort))
serverSocket.settimeout(3)


ENTITY = 2
HEADER_SIZE = 8

print('-'*40,"PHASE A",'-'*40)
print('The server is ready to receive')
ClientMessage, clientAddress = serverSocket.recvfrom(1024)


# Unpack client packet
Client_data_length, pcode, ClientEntity, data = struct.unpack(f'!IHH{(len(ClientMessage)-HEADER_SIZE)}s', ClientMessage)

# Decode the data from the packet
data = data.decode()

print("CLIENT PACKET: ", ClientMessage)
print(Client_data_length, pcode, ClientEntity, data)

# Generate Random Integers for the server packet
data_length = 16
repeat = random.randint(5,20)
udp_port = random.randint(20000, 30000)
len = random.randint(50,100)
codeA = random.randint(100,400)

# Create Server Packet and send it
ServerPacket = struct.pack('!IHHIIHH', data_length, pcode, ENTITY, repeat, udp_port, len, codeA)
serverSocket.sendto(ServerPacket, clientAddress)
serverSocket.close()


print('-'*40,"PHASE B",'-'*40)
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(("", udp_port))
serverSocket.settimeout(3)

data_length = 4

i = 0
while i < repeat:
    ClientMessage, clientAddress = serverSocket.recvfrom(1024)
    if(random.randint(1,5) != 1):
        Client_Packet = struct.unpack(f'!IHHI{len+len%4}s',ClientMessage)
        print("CLIENT PACKET: ", Client_Packet[:3])
        Client_data_length, pcode, entity, packet_id, Client_data = struct.unpack(f'!IHHI{len+len%4}s',ClientMessage)
        ack = struct.pack('!IHHI', data_length, pcode, ENTITY, packet_id)
        serverSocket.sendto(ack, clientAddress)
        i += 1
    else:
        print("OOPS Idropped my packey")

data_length = 6
tcp_port = random.randint(20000, 30000)
codeB = random.randint(100,400)
ServerPacket = struct.pack('!IHHIH', data_length, pcode, ENTITY, tcp_port, codeB)
serverSocket.sendto(ServerPacket, clientAddress)
serverSocket.close()
print('-'*40,"PHASE C",'-'*40)


sys.exit()#Terminate the program after sending the corresponding data