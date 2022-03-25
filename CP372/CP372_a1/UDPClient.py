

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
sentence = input(' Input lower case sentence: ')

pcode = 0
entity = 1
data = sentence.encode() + bytearray(4-len(sentence)%4) 
data_length = len(data)

packet = struct.pack(f"!IHH{data_length}s", data_length , pcode, entity, data)

clientSocket.sendto( packet, (serverName, serverPort))
modifiedSentence, serverAddress = clientSocket.recvfrom(2048)

print('From server: ', modifiedSentence.decode())
clientSocket.close()

# Packet:
# Data_length: 4 bytes
# pcode: 2 bytes
# Entity: 2 bytes

# Data: any byte size divisible by 4 

