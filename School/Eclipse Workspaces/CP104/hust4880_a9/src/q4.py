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
from a9_functions import valid_sn_file

srl_file = open('serial_number.txt','r')
valid_file = open('output_valid.txt','a')
invalid_file = open('output_invalid.txt','a')

valid_sn_file(srl_file, valid_file, invalid_file)

srl_file.close()
valid_file.close()
invalid_file.close()