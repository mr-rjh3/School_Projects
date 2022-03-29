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
from functions import file_copy_n

fv_1 = open('words.txt','r')
fv_2 = open('new_words.txt', 'a')

n = int(input(""))

file_copy_n(fv_1, fv_2, n)