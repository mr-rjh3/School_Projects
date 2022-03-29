"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2020-03-25"
------------------------------------------------------------------------
"""
def hash_table(slots, values):
    """
    -------------------------------------------------------
    Print a hash table of a set of values. The format is:
Hash     Slot Key
-------- ---- --------------------
 1652346    3 Dark City, 1998
  848448    6 Zulu, 1964
    Do not create an actual Hash_Set.
    
    Use: hash_table(slots, values)
    -------------------------------------------------------
    Parameters:
       slots - the number of slots available (int > 0)
       values - the values to hash (list of ?)
    Returns:
       None
    -------------------------------------------------------
    """
    print("Hashes")
    print("{}{:>9}{:>4}".format('Hash','Slot','Key'))
    print("{}{:>5}{:>21}".format('========','====','===================='))
    for i in values:
        print("{:>8}{:>5} {}".format(hash(i), hash(i) % slots, i.key()))
    return 
    
 
    
    
    
    