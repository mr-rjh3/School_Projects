'''
Created on Feb 24, 2015

@author: Matthew
'''
from xmlrpc.server import SimpleXMLRPCServer
from xmlrpc.client import ServerProxy, Error

from xmlrpc.server import SimpleXMLRPCRequestHandler
import subprocess
import os

"""
def serving():
    subprocess.call(['C:/Users/Matthew/Desktop/Marking/20114cp104/runningJavaFiles/src/client.class', ["Localhost",5555,7777,"test.png",0,5]])
def div(self, x, y):
        return x // y
class RequestHandler(SimpleXMLRPCRequestHandler):
    rpc_paths = ('/RPC2',)
server = SimpleXMLRPCServer(("localhost", 8000),requestHandler=RequestHandler)


server.register_function(serving, 'serving')
server.register_function(div, 'div')

server.serve_forever()
"""

class RequestHandler(SimpleXMLRPCRequestHandler):
    rpc_paths = ('/RPC2',)

# Create server
server = SimpleXMLRPCServer(("104.236.62.77", 8000),
                            requestHandler=RequestHandler)
server.register_introspection_functions()


def serving():
    #fork here call subprocess within child.
    subprocess.Popen(['java',"Server","Localhost","5000", "5000", "5000"])

#    subprocess.call(['C:/Users/Matthew/Desktop/Marking/20114cp104/runningJavaFiles/src/client.class', ["Localhost","5555","7777","test.png","0","5"]])
    return 1
server.register_function(serving, 'serving')



# Run the server's main loop
print("Server is started")
print(os.getcwd())
server.serve_forever()
