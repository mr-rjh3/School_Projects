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
h_set = Hash_Set(2)

for i in range(40):
    h_set.insert(i)
h_set.debug()

for i in range(41):
    h_set.insert(i)
h_set.debug()