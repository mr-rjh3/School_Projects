"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-11-14"
------------------------------------------------------------------------
"""
from functions import parse_code

product_code = 'ATV3482S14'
pc,pi,pq = parse_code(product_code)
print(pc,pi,pq)