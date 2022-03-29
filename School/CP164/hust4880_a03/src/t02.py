"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2020-01-30"
------------------------------------------------------------------------
"""
from Stack_array import Stack

stk = Stack()
stk.push(5)
stk.push(7)
stk.push(8)
stk.push(9)
stk.push(12)
stk.push(14)
stk.push(8)

target1, target2 = stk.split_alt()
for i in target1:
    print(i)
print()
for i in target2:
    print(i)
