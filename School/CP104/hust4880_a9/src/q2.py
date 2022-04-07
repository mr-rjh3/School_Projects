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

from a9_functions import find_median
my_file = open('numbers.txt','r')

numbers, median = find_median(my_file)

my_file.close()

out_file = open('output_q2.txt','a')

out_file.write('{}={}'.format(numbers, median))

out_file.close()


