"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-10-10"
------------------------------------------------------------------------
"""
from a3_functions import base_price, time_dicount, length_dicount

call_length = int(input("Length of call (minutes): "))
hour = int(input("Hour of call (24hour format): "))

total_price = base_price(call_length)
total_price = time_dicount(total_price, hour)
total_price = length_dicount(total_price, call_length)

print("Total price of call: ${:.2f}".format(total_price))    