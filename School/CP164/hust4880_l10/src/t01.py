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
from test_Sorts_array import create_randoms, create_reversed, create_sorted

l1 = create_sorted()
l2 = create_reversed()
l3 = create_randoms()
for i in l1:
    print(i, ',', end = '')
print()
for i in l2:
    print(i, ',', end = '')
print()
for i in l3:
    for j in i:
        print(j, ',', end = '')    
