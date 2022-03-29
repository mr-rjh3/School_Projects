"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-11-05"
------------------------------------------------------------------------
"""
from a7_functions import win_game

game_list = win_game()
redn = game_list[0]
greenn = game_list[1]

print('Number of "red" entered: {}'.format(redn))
print('Number of "green" entered: {}'.format(greenn))

if(redn > greenn):
    print('"red" team wins!!!')
elif(redn < greenn):
    print('"green" team wins!!!')
else:
    print("It's a tie!!!")