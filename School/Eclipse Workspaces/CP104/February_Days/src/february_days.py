"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston, Ivan Lin
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019 M10 3"
------------------------------------------------------------------------
"""
'''
# Question
February Days
The month of February normally has 28 days. But if it is a leap year, February has 29 days.
Write a program that asks the user to enter a year. The program should then display the
number of days in February that year. Use the following criteria to
identify leap years:
1. Determine whether the year is divisible by 100. If it is, then it is a leap year if and only
if it is also divisible by 400. For example, 2000 is a leap year, but 2100 is not.
2. If the year is not divisible by 100, then it is a leap year if and only if it is divisible by 4.
For example, 2008 is a leap year, but 2009 is not.
'''

year = int(input("Enter a year: "))
if((year%100 == 0) and (year%400 == 0)):
    print("February will have 29 days since it is a leap year.")
    
elif((year%100 == 0) and (year%400 != 0)):
    print("February will have 28 days since it is a not leap year.")
    
elif((year%100 != 0) and (year%4 == 0)):
    print("February will have 29 days since it is a leap year.")
    
else:
    print("February will have 28 days since it is not a leap year.")
