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
from functions import insert_words, comparison_total
from Hash_Set_array import Hash_Set
from Word import Word

'''
hs = Hash_Set(2)
for i in range(40):
    hs.insert(i)
for i in hs:
    print(i)
'''


hash_set = Hash_Set(20)
fv = open('miserables.txt','r')
insert_words(fv, hash_set)
fv.close()



total_comparisons, max_word = comparison_total(hash_set)


print('Total Comparisons: {:,}'.format(total_comparisons))
print('Max word: {} {:,}'.format(max_word.word, max_word.comparisons))

