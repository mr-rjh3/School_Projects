"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-09-26"
------------------------------------------------------------------------
"""

MINUTES = 60
DAYS = 24

seconds = int(input("Number of seconds: "))


minutes = seconds//60
hours = minutes// MINUTES
days = hours // DAYS

seconds_remaining = seconds % 60
minutes_remaining = minutes % 60
hours_remaining = hours % 24

print("Days: {}, Hours: {}, Minutes: {}, Seconds: {}".format(days, hours_remaining, minutes_remaining, seconds_remaining))


