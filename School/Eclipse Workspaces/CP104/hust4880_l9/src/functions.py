"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-11-14"
------------------------------------------------------------------------
"""

def url_categorize(url):
    """
    -------------------------------------------------------
    Returns whether a url represents a business, a non-profit, or another
    type of organization.
    Use: url_type = url_categorize(url)
    -------------------------------------------------------
    Parameters:
        url - the web address of the organization (str)
    Returns:
        url_type - the organization type (str)
            'business' if url ends with 'com'
            'non-profit' if url ends with 'org'
            'other' if url ends with something else
    ------------------------------------------------------
    """
    i = url.rfind('.')
    if(url[i:] == '.com'):
        url_type = 'business'
    elif(url[i:] == '.org'):
        url_type = 'non-profit'
    else:
        url_type = 'other'
    
    return url_type


def parse_code(product_code):
    """
    -------------------------------------------------------
    Parses a given product code. A product code has three parts:
        The first three letters describe the product category
        The next four digits are the product ID
        The remaining characters describe the product's qualifiers
    Use: pc, pi, pq = parse_code(product_code)
    -------------------------------------------------------
    Parameters:
        product_code - a valid product code (str)
    Returns:
        pc - the category part of product_code (str)
        pi - the id part of product_code (str)
        pq - the qualifier part of product_code (str)
    -------------------------------------------------------
    """
    
    pc = product_code[0:3]
    pi = product_code[3:7]
    pq = product_code[7:]
    return pc,pi,pq
    
    
    
def validate_code(product_code):
    """
    -------------------------------------------------------
    Parses a given product code and prints whether the various parts are valid.
    A product code has three parts:
        The first three letters describe the product category and must
        all be in upper case.
        The next four digits are the product ID.
        The remaining characters describe the product's qualifiers,
        such as colour, size, etc. and always begins with an uppercase letter.
    Use: validate_code(product_code)
    -------------------------------------------------------
    Parameters:
        product_code - a product code (str)
    Returns:
        None
    -------------------------------------------------------
    """
    pc = product_code[0:3]
    pi = product_code[3:7]
    pq = product_code[7:]
    
    
    
    if(pc.isupper() and len(pc) == 3):
        print('Category {} is valid.'.format(pc))
    else:
        print('Category {} is not valid.'.format(pc))
        
        
    if(pi.isdigit() and len(pi) == 4):
        print('ID {} is valid.'.format(pi))
    else:
        print('ID {} is not valid.'.format(pi))
    
    if(pq[0].isupper()):
        print('Qualifier {} is valid.'.format(pq))
    else:
        print('Qualifier {} is not valid.'.format(pq))
    
    return None
    
def count_special_chars(s):
    """
    -------------------------------------------------------
    Counts the number of special characters in s.
    The special characters are: "#", "@", "$", "%", "&", "!".
    Use: count = count_special_chars(s)
    -------------------------------------------------------
    Parameters:
        s - a string (str)
    Returns:
        count - number of special characters in s (int)
    ------------------------------------------------------
    """
    special = "#@$%&!"
    count = 0
    for i in special:
        count += s.count(i)
    return count
    
def total_digits(s):
    """
    -------------------------------------------------------
    Extracts and calculates the total of all digits in s.
    Use: total = total_digits(s)
    -------------------------------------------------------
    Parameters:
        s - a string (str)
    Returns:
        total - total of all the digits in s (int)
    ------------------------------------------------------
    """
    total = 0
    for i in s:
        if(i.isdigit()):
            total += int(i)
    
    
    return total
    
    
    
    
    