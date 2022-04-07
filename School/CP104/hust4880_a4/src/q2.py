"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-10-2"
------------------------------------------------------------------------
"""
import q2_functions

def main():
    
    solution = q2_functions.math_quiz()
    n = int(input("Answer: "))
    
    if(n == solution):
        print("Congratulations, correct answer!")
    else:
        print("Incorrect - the answer should be: ", solution)
        
main()
    