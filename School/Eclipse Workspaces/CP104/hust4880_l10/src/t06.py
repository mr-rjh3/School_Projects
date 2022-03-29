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
from functions import number_stats

fv = open('numbers.txt', 'r')
smallest, largest, total, average = number_stats(fv)
print(smallest, largest, total, average)