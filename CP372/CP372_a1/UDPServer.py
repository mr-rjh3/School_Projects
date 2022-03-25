# Import socket module
from socket import * 
import sys # In order to terminate the program
import struct

# Assign a port number
serverPort = 12000
serverSocket = socket(AF_INET, SOCK_DGRAM)

# Bind the socket to server address and server port
serverSocket.bind(("", serverPort))

while True:

	print('The server is ready to receive')
	
	ClientMessage, clientAddress = serverSocket.recvfrom(1024)
	print(ClientMessage)
	serverSocket.sendto(ClientMessage[8:], clientAddress)

serverSocket.close()  
sys.exit()#Terminate the program after sending the corresponding data
