"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2020-03-26"
------------------------------------------------------------------------
"""
from Hash_Set_array import Hash_Set
h_set = Hash_Set(7)

for i in range(20):
    h_set.insert(i)
h_set.debug()
h_set.remove(0)
print()
h_set.debug()