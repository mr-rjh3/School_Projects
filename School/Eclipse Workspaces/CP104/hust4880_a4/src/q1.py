"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-10-1"
------------------------------------------------------------------------
"""
import q1_functions

def main():
    income = int(input("Enter your income: $ "))
    federal_tax = q1_functions.calc_federal_tax(income)
    prov_tax = q1_functions.calc_prov_tax(income)
    total_tax = federal_tax + prov_tax
    print("Your total tax liability is: $ {:.0f}".format(total_tax))
    print("[details federal tax: $ {:.0f}, state tax: $ {:.0f}]".format(federal_tax, prov_tax))

main()
    
    
    
    
    
    
    