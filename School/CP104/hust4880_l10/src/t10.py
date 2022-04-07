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

from functions import count_frequency_word

fv = open('words.txt','r')
word = 'Exercise'

count = count_frequency_word(fv, word)

print(count)