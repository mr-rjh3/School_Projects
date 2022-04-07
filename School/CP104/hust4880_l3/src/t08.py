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

height = float(input("Enter your height (m): "))
weight = int(input("Enter your weight (kg): "))
BMI = float(input("Enter your upper limit BMI (23 if you are from South East Asia and Southern China, 25 for everyone else): "))
userBMI = weight / height**2
BMI_prime = userBMI/BMI

print("Body Mass Index (kg/m^2) = {:.2f}".format(userBMI))
print("BMI Prime = {:.2f}".format(BMI_prime))