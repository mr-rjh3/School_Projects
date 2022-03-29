"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-10-24"
------------------------------------------------------------------------
"""
from a6_functions import is_prime

while(True):
    num = float(input("Enter a positive integer: "))
    if(num > 0 and int(num) == num):
        num = int(num)
        break
    
prime = is_prime(num)

if(prime):
    print("{} is a prime number".format(num))
else:
    print("{} is not a prime number".format(num))