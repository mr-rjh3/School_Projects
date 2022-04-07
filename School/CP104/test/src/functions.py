"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019 M10 1"
------------------------------------------------------------------------
"""

def greatest(lst):
    x = 0
    for i in lst:
        if(i >= x):
            x = i
    return x


def greetings(name):
    print(name)
    
def avg(n1, n2, n3):
    average = n1 + n2 + n3
    return average

def divides_evenly(x,y):
    if(x%y == 0):
        divide = True
    else:
        divide = False
    return divide

def prime_num(x):
    prime = True
    for i in range(2, x):
        for j in range(2,x):
            if(x%j == 0):
                prime = False
                break
    return prime





