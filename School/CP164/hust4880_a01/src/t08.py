"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2020-01-16"
------------------------------------------------------------------------
"""
from functions import file_analyze

fv = open('file.txt', 'r')

print (file_analyze(fv))

fv.close()