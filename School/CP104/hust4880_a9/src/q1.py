"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-11-20"
------------------------------------------------------------------------
"""
from a9_functions import sum_numbers
numbers = []
my_file = open('text_numbers.txt','r')

numbers, total = sum_numbers(my_file)

my_file.close

write_file = open('output_q1.txt','a')

nums = str(numbers).replace(',', ' +')
output = '{}={}'.format(nums, total)

write_file.write(output)

write_file.close
