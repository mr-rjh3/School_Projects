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
from functions import list_stats


values = [1, 2, 39, 10, 2929, 38, 37, -92, 88]

print("Values: ", values)

smallest, largest, total, average = list_stats(values)
print(smallest)
print(largest)
print(total)
print(average)