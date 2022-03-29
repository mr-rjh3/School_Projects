'''
Created on Feb 22, 2015

@author: Matthew
'''
#server = ServerProxy("")

# simple test program (from the XML-RPC specification)

# server = ServerProxy("http://localhost:8000") # local server
from xmlrpc.client import ServerProxy, Error
import subprocess
#proxy = xmlrpclib.ServerProxy("http://localhost:8000/")
#prox = ServerProxy("http://localhost:8000/")
#prox.request('C:/Users/Matthew/Desktop/Marking/20114cp104/runningJavaFiles/src/client.class', ["Localhost",5555,7777,"test.png",0,5])
#server = ServerProxy("http://localhost:8000/")
#print(server.div(4,3))
import time


s = ServerProxy('http://104.236.62.77:8000', verbose=True)
times=[]
FILES=["test_short.txt ","accelerator.jpg ", "test_medium.txt ","homura.png ","test_long.txt ","test_border.txt "]
RELIABILITYNUM=["0 ","5 ","100 "]
WINDOWSIZE=["1 ", "10 ", "40 ", "80 "]
TIMEOUTS = ["100 ","300 ", "500 "]
f = open( "results.csv", "w+", encoding="utf-8" )        
for windowNum in WINDOWSIZE:
    for reliab in RELIABILITYNUM:
        for fileName in FILES:
            for timeing in TIMEOUTS:
                s.serving()
                start = time.time()
                subprocess.call(['java ',["Client ","104.236.62.77 ","5555 ","7777 ",fileName,reliab,windowNum,timeing]])
                end = time.time()
                item=[fileName+','+reliab+','+windowNum+','+timeing, end - start]
                cur=str(item).strip('[').strip(']').replace("'",'').replace(" ","")
                f.write(cur+"\n")
                f.flush()
f.close()
    