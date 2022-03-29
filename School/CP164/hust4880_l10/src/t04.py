"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2020-04-01"
------------------------------------------------------------------------
"""
from test_Sorts_List_linked import SORTS, SIZE, test_sort 

print(
'''
n:   {}       |      Comparisons       | |         Swaps          |
Algorithm      In Order Reversed   Random In Order Reversed   Random
-------------- -------- -------- -------- -------- -------- --------    
'''.format(SIZE)
    )
for i in SORTS:
    test_sort(i[0], i[1])

