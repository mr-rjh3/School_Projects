"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019 09 26"
------------------------------------------------------------------------
"""

n = int(input('Enter a positive two digit integer: '))
n1 = n // 10
n2 = n % 10
n_sum = n1 + n2
print("The sum of the two digits in the integer ({}) is: {}".format(n, n_sum))
