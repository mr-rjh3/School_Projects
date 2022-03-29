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
from functions import union

source1 = [3, 4, 2, 1, 1, 3, 5, 6, 7, 7, 2, 3]
source2 = [3, 6, 8, 3, 3, 2, 2, 1, 1, 7, 8, 4, 5]
print('Values 1: ', source1)
print('Values 2: ', source2)
target = union(source1, source2)
#source1, source2 = [10, 3, 10, 3, 1], [8, 2, 7, 3, 6, 10, 32, 99]
print("Union:", target)
