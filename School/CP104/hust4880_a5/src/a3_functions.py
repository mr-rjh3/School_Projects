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

COST_PER_MIN = 0.08
EARLY_DISCOUNT = 0.50
LATE_DISCOUNT = 0.25

def base_price(call_length):
    """
    -------------------------------------------------------
    Determines the base price of a long distance call
    Use: price = base_price(call_length)
    -------------------------------------------------------
    Parameters:
        call_length - The length of time the call took to finish (int)
    Returns:
        base_price - price of call before potential discounts (float)
    -------------------------------------------------------
    """
    price = call_length*COST_PER_MIN
    return price

def time_dicount(price, hour):
    """
    -------------------------------------------------------
    Determines the discount on a long distance call based on the hour the call took place
    Use: discount_price = time_discount(base_price, hour)
    -------------------------------------------------------
    Parameters:
        price - the base price of the call (float)
        hour - The hour when the call took place (int)
    Returns:
        discount_price - the price of call after the time discount (float)
    -------------------------------------------------------
    """
    if((hour >= 0) and (hour <= 8)):
        discount = price*EARLY_DISCOUNT
    elif((hour >=18) and (hour <= 23)):
        discount = price*LATE_DISCOUNT
    else:
        discount = 0
    discount_price = price - discount
    return discount_price
    
def length_dicount(price, call_length):
    """
    -------------------------------------------------------
    Determines the discount on a long distance call based on the length of the call
    Use: total_price = length_discount(discount_price, hour)
    -------------------------------------------------------
    Parameters:
        discount_price - the price of the call after a potential time discount (float)
        call_length - The length of the call (int)
    Returns:
        total_price - the price of call after the length discount (float)
    -------------------------------------------------------
    """
    if(call_length >= 30):
        discount = price*call_length
    else:
        discount = 0
    total_price = price - discount
    return total_price
    
    
    
    
    