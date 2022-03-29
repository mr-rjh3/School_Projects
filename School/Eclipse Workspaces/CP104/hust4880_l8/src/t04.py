"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-11-07"
------------------------------------------------------------------------
"""
from functions import generate_integer_list

n = int(input("How many num: "))
low = int(input("Lowest integer: "))
high = int(input("Highest integer: "))

values = generate_integer_list(n, low, high)
print(values)