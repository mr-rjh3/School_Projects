"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-11-29"
------------------------------------------------------------------------
"""
from a10_functions import add_matricies


matrix_1 = [[]]
matrix_2 = [[]]
values = []
counter = 0
counterM = 0


while(counter < 12):
    values.append(float(input("Enter inputpls: ")))
    counter += 1
    
counter = 0

while (counter < 6):
    matrix_1[counterM].append(values[counter])
    if(counter%2 != 0 and counter != 5):
        matrix_1.append([])
        counterM += 1
    counter += 1


counterM = 0
while (counter >= 6 and counter < 12):
    matrix_2[counterM].append(values[counter])
    if(counter%2 != 0 and counter != 11):
        matrix_2.append([])
        counterM += 1
    counter += 1



print(matrix_1, matrix_2)
matrix_sum = add_matricies(matrix_1, matrix_2)
print(matrix_sum)
    

    
    