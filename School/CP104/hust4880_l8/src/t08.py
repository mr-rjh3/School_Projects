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
from functions import linear_search

a = [1,2,8,4,3]
print('Values: ', a)
v = int(input("Enter Value to find: "))
index = linear_search(a, v)
print('Index of ', v, ': ', index)