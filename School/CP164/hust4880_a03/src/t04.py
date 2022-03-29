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
target = Stack()
source1 = Stack()
source2 = Stack()

source2.push(14)
source2.push(9)

source2.push(7)
source2.push(1)
source2.push(6)
source2.push(3)

source1.push(8)
source1.push(12)
source1.push(8)
source1.push(5)

target.combine(source1, source2)
for i in target:
    print(i)