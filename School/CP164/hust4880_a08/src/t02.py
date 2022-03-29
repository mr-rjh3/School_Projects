"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2020-03-27"
------------------------------------------------------------------------
"""
from Letter import Letter
from BST_linked import BST
from functions import do_comparisons, comparison_total, letter_table
DATA1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
DATA2 = "MFTCJPWADHKNRUYBEIGLOQSVXZ"
DATA3 = "ETAOINSHRDLUCMPFYWGBVKJXZQ"

bst1 = BST()
bst2 = BST()
bst3 = BST()
for i in DATA1:
    bst1.insert(Letter(i))
for i in DATA2:
    bst2.insert(Letter(i))
for i in DATA3:
    bst3.insert(Letter(i))


fv = open('miserables.txt', 'r')
do_comparisons(fv, bst1)
print("book 1 complete")
do_comparisons(fv, bst2)
print("book 2 complete")
do_comparisons(fv, bst3)
print("book 3 complete")
fv.close()

print(comparison_total(bst1),comparison_total(bst2),comparison_total(bst3)) 
#the third BST is the fasted as it has the least amount of comparisons
print()
letter_table(bst1)
print()
letter_table(bst2)
print()
letter_table(bst3)

