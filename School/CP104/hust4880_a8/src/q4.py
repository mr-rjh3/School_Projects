"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-11-15"
------------------------------------------------------------------------
"""
from a8_functions import is_word_chain

my_list = []
while(True):
    my_str = input('Enter Words here, To stop enter empty string: ')
    if(my_str == ''):
        break
    else:
        my_list.append(my_str)

is_chain = is_word_chain(my_list)
if(is_chain):
    print('{} is a word chain'.format(my_list))
else:
    print('{} is not a word chain'.format(my_list))
