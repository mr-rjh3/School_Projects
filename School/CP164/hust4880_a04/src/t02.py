"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2020-02-06"
------------------------------------------------------------------------
"""
from functions import pq_split_key
from Priority_Queue_array import Priority_Queue

pq = Priority_Queue()
for i in range (0,10):
    pq.insert(i)
    

target1, target2 = pq_split_key(pq, 5)
for i in target1:
    print(i)
for i in target2:
    print(" ",i)