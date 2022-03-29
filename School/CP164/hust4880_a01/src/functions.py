"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2020-01-07"
------------------------------------------------------------------------
"""

VWLS = 'aeiou'

def max_diff(a):
    """
    -------------------------------------------------------
    Returns maximum absolute difference between adjacent values in a list.
    Use: md = max_diff(a)
    -------------------------------------------------------
    Parameters:
        a - a list of values (list of int)
    Returns:
        md - the largest absolute difference between adjacent
            values in a (int)
    -------------------------------------------------------
    """
    md = 0
    for i in range(len(a) - 1):
        if(i != len(a)):
            if(md < abs(a[i] - a[i+1])):
                md = abs(a[i] - a[i+1])
    return md

def is_valid(name):
    """
    -------------------------------------------------------
    Determines if name is a valid Python variable name.
    Variables names must start with a letter or an underscore.
    The rest of the variable name may consist of letters, numbers
    and underscores.
    Use: valid = is_valid(name)
    -------------------------------------------------------
    Parameters:
        name - a string to test as a Python variable name (str)
    Returns:
        valid - True if name is a valid Python variable name,
            False otherwise (boolean)
    -------------------------------------------------------
    """
    valid = True
    i = 1
    if(name[0].isalpha() or name[0] == '_'):
        while(valid and i in range (1, len(name))):
            if(name[i].isalpha() or name[i].isnumeric() or name[i] == '_'):
                valid = True
            else:
                valid = False
            i += 1
    else:
        valid = False
            
    return valid
            
def matrix_stats(a):
    """
    -------------------------------------------------------
    Determines the smallest, largest, total, and average of
    the values in the 2D list a.
    Use: small, large, total, average = matrix_stats(a):
    -------------------------------------------------------
    Parameters:
        a - a 2D list of numbers (2D list of float)
    Returns:
        small - the smallest number in a (float)
        large - the largest number in a (float)
        total - the total of all numbers in a (float)
        average - the average of all numbers in a (float)
    -------------------------------------------------------
    """
    small = a[0][0]
    large = a[0][0]
    total = 0
    counter = 0
    for i in a:
        for j in i:
            if(j < small):
                small = j
            if(j > large):
                large = j
            total += j
            counter += 1
    average = total/counter
    
    return small, large, total, average

def matrix_flatten(a):
    """
    -------------------------------------------------------
    Flatten the contents of 2D list a. A 'flattened' list is a
    2D list that is converted into a 1D list.
    Use: b = matrix_flatten(a):
    -------------------------------------------------------
    Parameters:
        a - a 2D list (2D list of ?)
    Returns:
        b - the flattened version of a (list of ?)
    -------------------------------------------------------
    """
    b = []
    for i in a:
        for j in i:
            b.append(j)
    return b

def matrixes_add(a, b):
    """
    -------------------------------------------------------
    Sums the contents of matrixes a and b. a and b must have
    the same number of rows and columns.
    Use: c = matrixes_add(a, b)
    -------------------------------------------------------
    Parameters:
        a - a 2D list (2D list of int/float)
        b - a 2D list (2D list of int/float)
    Returns:
        c - the matrix sum of a and b (2D list of int/float)
    -------------------------------------------------------
    """
    assert len(a) == len(b) and len(a[0]) == len(b[0])
    c = []
    for i in range (len(a)):
        c.append([])
        for j in range (len(a[i])):
            c[i].append(a[i][j] + b[i][j])
    return c
    
def matrixes_multiply(a, b):
    """
    -------------------------------------------------------
    Multiplies the contents of matrixes a and b.
    If a is mxn in size, and b is nxp in size, then c is mxp.
    Use: c = matrixes_multiply(a, b)
    -------------------------------------------------------
    Parameters:
        a - a 2D list (2D list of int/float)
        b - a 2D list (2D list of int/float)
    Returns:
        c - the matrix multiple of a and b (2D list of int/float)
    -------------------------------------------------------
    """
    assert len(a) == len(b[0]) and len(a[0]) == len(b)
    
    c = []
    d = 0
    flag = True
    go = 0
    
    for i in range(len(a)):
        c.append([])
        
        for j in range(len(b)):
            d += a[i][j]*b[j][i+go]
        c[i].append(d)
        d = 0

        if(flag):
            go = -1
        else:
            go = 0
            
        for j in range(len(b)):
            d += a[i][j]*b[j][i+go]
        
        c[i].append(d)
        d = 0
        flag = False
 
    return c
    
def matrix_rotate_right(a):
    """
    -------------------------------------------------------
    Returns a copy of a 2D matrix rotated to the right.
    Use: b = matrix_rotate_right(a)
    -------------------------------------------------------
    Parameters:
        a - a 2D list of values (2d list of int/float)
    Returns:
        b - the rotated 2D list of values (2D list of int/float)
    -------------------------------------------------------
    """
    b = []
    for i in range(len(a[0])):
        b.append([])
        for j in range(len(a)-1, -1, -1):
            b[i].append(a[j][i])
    
    return b
    
def file_analyze(fv):
    """
    -------------------------------------------------------
    Analyzes the characters in a file.
    Use: u, l, d, w, r = file_analyze(fv)
    -------------------------------------------------------
    Parameters:
        fv - an already open file reference (file variable)
    Returns:
        u - the number of uppercase letters in the file (int)
        l - the number of lowercase letters in the file (int)
        d - the number of digits in the file (int)
        w - the number of whitespace characters in the file (int)
        r - the number of remaining characters in the file (int)
    -------------------------------------------------------
    """
    u = 0
    l = 0
    d = 0
    w = 0
    r = 0
    for i in fv.readlines():
        i = i.strip('\n')
        for j in i:
            if(j.isalpha()):
                if(j.isupper()):
                    u += 1
                elif(j.islower()):
                    l += 1
            elif(j.isdigit()):
                d += 1
            elif(j == ' '):
                w += 1
            else:
                r += 1
    return u, l, d, w, r
            
def dsmvwl(s):
    """
    -------------------------------------------------------
    Disemvowels a string. out contains all the characters in s
    that are not vowels. ('y' is not considered a vowel.) Case is preserved.
    Use: out = dsmvl(s)
    -------------------------------------------------------
    Parameters:
       s - a string (str)
    Returns:
       out - s with the vowels removed (str)
    -------------------------------------------------------
    """
    out = ''
    for i in s:
        if (i.lower() not in VWLS):
            out += i
    return out
    
def pig_latin(word):
    """
    -------------------------------------------------------
    Converts a word to Pig Latin. The conversion is:
    - if a word begins with a vowel, add "way" to the end of the word.
    - if the word begins with consonants, move all consonants to the
    end of the word and add "ay" to the end of that.
    "y" is treated as a consonant if it is the first character in the word,
    and as a vowel for anywhere else in the word.
    Preserve the case of the word - i.e. if the first character of word
    is upper-case, then the new first character should also be upper case.
    Use: pl = pig_latin(word)
    -------------------------------------------------------
    Parameters:
        word - a string to convert to Pig Latin (str)
    Returns:
        pl - the Pig Latin version of word (str)
    ------------------------------------------------------
    """
    pl = ''
    cons = ''
    i = 0
    flag = False
    
    if(word[0].lower() in VWLS):
        pl = word
        pl += 'way'
    else:
        while (i in range(len(word)) and not flag):
            if(word[i].lower() in VWLS or word[i].lower() == ''):
                flag = True
            else:
                cons += word[i]
            i += 1
        pl += word.strip(cons)
        pl += cons
        pl += 'ay'
    pl = pl.lower()
    if(word[0].isupper()):
        pl = pl.capitalize()
        
                
                
    
    return pl
    