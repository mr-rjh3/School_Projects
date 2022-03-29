"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2020-04-02"
------------------------------------------------------------------------
"""
from Word import Word
from Hash_Set_array import Hash_Set

def insert_words(fv, hash_set):
    """
    -------------------------------------------------------
    Retrieves every Word in fv and inserts into
    a Hash_Set.
    Each Word object in hash_set contains the number of comparisons
    required to insert that Word object from file_variable into hash_set.
    -------------------------------------------------------
    Parameters:
        fv - the already open file containing data to evaluate (file)
        hash_set - the Hash_Set to insert the words into (Hash_Set)
    Returns:
        None
    -------------------------------------------------------
    """
    words = fv.read().lower().split()
    for word in words:
        if(word.isalpha()):
            hash_set.insert(Word(word))
    return 

def comparison_total(hash_set):
    """
    -------------------------------------------------------
    Sums the comparison values of all Word objects in hash_set.
    -------------------------------------------------------
    Parameters:
        hash_set - a hash set of Word objects (Hash_Set)
    Returns:
        total - the total of all comparison fields in the Hash_Set
            Word objects (int)
        max_word - the word having the most comparisons (Word)
    -------------------------------------------------------
    """
    total = 0
    max_comparisons = 0

    for i in hash_set:
        total += i.comparisons
        if(i.comparisons > max_comparisons):
            max_comparisons = i.comparisons
            max_word = i
    return total, max_word

    
    