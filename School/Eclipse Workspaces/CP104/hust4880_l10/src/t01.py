"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-11-21"
------------------------------------------------------------------------
"""
from functions import customer_record

fv = open('customers.txt', 'r')
n = int(input(""))

result = customer_record(fv, n)

print(result)

