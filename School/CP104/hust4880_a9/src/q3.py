"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-11-23"
------------------------------------------------------------------------
"""
from a9_functions import analysis_file

file_in = open('text.txt','r')

upper, lower, digit, space = analysis_file(file_in)

file_in.close()

output = open('output_q3.txt','a')

output.write('{},{},{},{}'.format(upper,lower,digit,space))

output.close()