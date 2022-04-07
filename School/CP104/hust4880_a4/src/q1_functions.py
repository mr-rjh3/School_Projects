"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-10-3"
------------------------------------------------------------------------
"""
F_TAX_1 = 0.15
F_TAX_2 = 0.25
F_TAX_3 = 0.35
P_TAX = 0.05

def calc_federal_tax(income):
    """
    -------------------------------------------------------
    Calculates the amount of federal tax from the income over $100,000
    Use: federal_tax = calc_federal_tax(income)
    -------------------------------------------------------
    Parameters:
    income - Total income to calculate tax from (float > 0)
    Returns
    federal_tax - Amount of federal tax calculated from the given income (float >= 0)
    -------------------------------------------------------
    """
    federal_tax = 0
    federal_tax += (35000 * F_TAX_1)
    federal_tax += ((100000 - 35001) * F_TAX_2)
    federal_tax += ((income - 100000) * F_TAX_3)
    return federal_tax

def calc_prov_tax(income):
    """
    -------------------------------------------------------
    Calculates the amount of provincial tax from income over $100,000
    Use: prov_tax = calc_prov_tax(income)
    -------------------------------------------------------
    Parameters:
    income - Total income used to calculate tax (float > 0)
    Returns
    prov_tax - Amount of provincial tax calculated from the given income (float >= 0)
    -------------------------------------------------------
    """
    prov_tax = (income - 50000) * P_TAX
    return prov_tax
