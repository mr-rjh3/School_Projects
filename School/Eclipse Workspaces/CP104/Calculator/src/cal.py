"""
------------------------------------------------------------------------
"09/24 - Class task
------------------------------------------------------------------------
Author: Riley Huston, Ben Randell, Ranjodh Singh, Ivan Lin, Daniel Frank
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019 09 24"
------------------------------------------------------------------------
"""

import math

def addition(op1, op2):
    sum = op1 + op2
    return sum
def subtraction(op1, op2):
    dif = op1 - op2
    return dif
def multiply(op1, op2):
    product = op1 * op2
    return product
def division(op1, op2):
    quotient = op1 / op2
    return quotient

def sin(op1):
    n = math.sin(op1)
    return n

def cosine(op1):
    n = math.cos(op1)
    return n

def tangent(op1):
    n = math.tan(op1)
    return n

def main():
    op1 = float(input("Enter number one: "))
    op2 = float(input("Enter number one: "))
    print(op1," + ", op2, " = ", addition(op1, op2))
    print(op1," - ", op2, " = ", subtraction(op1, op2))
    print(op1," * ", op2, " = ", multiply(op1, op2))
    print(op1," / ", op2, " = ", division(op1, op2))
    print("sin",op1," = ",(op1))
    print("cos",op1," = ",cosine(op1))
    print("tan",op1," = ",tangent(op1))
    
main()









