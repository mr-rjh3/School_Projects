"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-09-23"
------------------------------------------------------------------------
"""


'''
# Question:
Write a program that takes two numbers as input.
If the first number is greater than the second number,
switch the value of both the variables with each other.
'''
'''
n1 = int(input())
n2 = int(input())
if(n1 > n2):
    n1, n2 = n2, n1
print(n1, n2)
'''




'''
# Question
Write a program that takes 5 numbers as input from the user.
It then asks the user which number to print.
User can enter: first, second, third, fourth, fifth, all, none
'''
'''
n1 = input()
n2 = input()
n3 = input()
n4 = input()
n5 = input()

num = input("what num")

if(num == "first"):
    print(n1)
elif(num == "second"):
    print(n2)
elif(num == "third"):
    print(n3)
elif(num == "fourth"):
    print(n4)
elif(num == "fifth"):
    print(n5)
elif(num == "all"):
    print(n1, n2, n3, n4, n5)
'''

''' 
# Question
February Days
The month of February normally has 28 days. But if it is a leap year, February has 29 days.
Write a program that asks the user to enter a year. The program should then display the
number of days in February that year. Use the following criteria to
identify leap years:
1. Determine whether the year is divisible by 100. If it is, then it is a leap year if and only
if it is also divisible by 400. For example, 2000 is a leap year, but 2100 is not.
2. If the year is not divisible by 100, then it is a leap year if and only if it is divisible by 4.
For example, 2008 is a leap year, but 2009 is not.
'''


'''
year = int(input("enter a year"))
if((year%100 == 0) and (year%400 == 0)):
    print("leapyear")
    
elif((year%100 == 0) and (year%400 != 0)):
    print("not")
    
elif(year%100 != 0 and year%4 == 0):
    print('leapyear')
    
else:
    print("not")
'''

'''
ASCII A - Z = 65 - 90
ASCII a - z = 97 - 122
ASCII 0 - 9 = 48 - 57

Operators : and, or, not
            &&   ||  !
'''

'''
if("Great" < "Greats"):
    print("Great < Greats")
if("GREAT" < "GRe"):
    print("GREAT < GRe")
if("ABCD" < "BCD"):
    print("ABCD < BCD")
if("A9b" < "A9B"):
    print("A9b < A9B")
'''  
'''  
marks = 80
if(marks > 80):
    grade = "A"
if(marks > 70):
    grade = "B"
if(marks > 60):
    grade = "C"
if(marks <= 60):
    grade = "F"

print(grade)
 
marks = 80
if (marks > 80):
    grade = "A"
elif (marks > 70) and (marks <= 80):
    grade = "B"
elif (marks > 60) and (marks <= 70):
    grade = "C"
else:
    grade = "F"
print(grade)
'''
  
'''
import functions
  
functions.greetings("Riley")
print(functions.avg(1, 2, 3))
  
'''
  
''' 
var1 = 1
var2 = 2
var3 = 3
var4 = 4

bool = True

if(bool):
    print(bool)
'''

'''print(var1 > 1)
print(var2 > 1)
print(var3 > 1)    
print(var4 > 1)

'''
'''y = 0
while(True):
    x = input("enter num")
    if(x == 'quit'):
        break   
    y += int(x)

print(y)
'''
'''    
#Random numbers
import random

#r1 = random.randint(1, 100)             #Random number between 1 - 100
#r2 = random.randrange(0, 101, 10)       #Random number between 0 - 101 with a step of 10
random.seed(10)                          #Changes the random seed to ten, default is time
print(random.randint(1, 100))
print(random.randint(1, 100))
print(random.randint(1, 100))
print(random.randint(1, 100))
print(random.randint(1, 100))
#print(r1 , r2)
'''

'''
def myfunction():
    print('dude')
    
def f():
    print('what')
'''


'''    
factorial = 1
n = int(input())
while(n > 0):
    factorial *= n
    n-=1
            
print(factorial)
'''

'''
for i in range(1,11):
    print(i)

x = 0
gogo = True
    
while gogo == True:
    x+=1
    print(x)
    if(x >= 100):
        gogo = false
'''

'''
var1 = 15
var1 = 15.0
var1 = "String"
var1 = [1,2,3,4]

if(isinstance(var1, list)):
    print("epic")
'''

'''    
var1 = int(input("Enter a number between 1 and 10: "))
try:
    result = 30 / var1
except:
    print("The input is not valid. Exiting... ")
    result = 'Error'
    exit()

print(result)
'''
    
'''
while(True):
        
    var1 = input("Enter a number between 1 and 10: ")
    
    try:
        var1 = int(var1)
        break
    except:
        print("The input is not valid.")
    
print("The input is: ", var1, type(var1))
'''

'''
var1 = int(input("Enter a number between 1 and 10: "))
try:
    result = 30 / var1
except:
    print("The input is not valid. Exiting... ")
else:
    print(result)
finally:
    print("Exit program")
'''

'''
var1 = int(input("Enter a number between 1 and 10: "))
try:
    if(var1 < 1 or var1 > 10):
        raise "Invalid Output"
except Exception as e:
    print("The input is not valid.")
else:
    result = 30 * 5
    print(result)
finally:
    print("Exit program")
'''
'''
while(True):
        
    try:
        var1 = int(input("Enter a number between 1 and 10: "))
        if(var1 < 1 or var1 > 10):
            raise "Invalid Output"
            print("Wrong Input")
        result = 30 / var1
    except Exception as e:
        print("The input is not valid.")
    else:
        print(result)
        break
'''


'''
lst = [0,1,2,3,4,5,6,7,13,9,10]
print(greatest(lst))
'''
'''


print(lst[1])
print(lst[-1])
print(lst[-2])
    
print(lst[1:3])
print(lst[1:5:3])
print(lst[:])
print(lst[1:])
print(lst[:3])
print(lst[-3:-1])
print(lst[5:1:-1])
print(lst[5:1:-2])
print(lst[0: len(lst)])
'''
'''
sum = 0
for Item in [1, 2, 3, 4]:
    Item = 1
    sum = sum + Item
print(sum)
'''
'''
str = 'Hello world'
indexofl = str.find('l')
indexr = str.rfind(' ', 0, indexofl)
print(indexofl)
print(indexr)
str = str.strip()

str = str.replace(' ', '')

str = str.lower()
print(str)

str = str.upper()
print(str)
'''
'''
Question: 
Write a program that extracts all the email addresses from
a long string. We assume there are spaces around the email addresses.
Specify any other valid assumption that you take."
'''
'''
email_addresses = input()
space_count = email_addresses.count(' ')
emails = []
space_index = []
for i in range(space_count):
    
    if(email_addresses[i] == '@'):
        index1 = email_addresses.find(' ', i, len(email_addresses))
        index2 = email_addresses.rfind(' ', 0, i)
        emails.append(email_addresses[index2:index1])

print(emails)
'''
   
'''
str1 = "this is really a string example....wow!!!"
str2 = "is"

print (str1.rfind(str2))

print (str1.rfind(str2, 0, 10))
print (str1.find(str2))
print (str1.find(str2, 0, 10))

#Files

file_object = open(filename, mode)
#mode = string ('r' = reading, 'w' = writing, '
'''

'''
f = open("my_file.txt", "r")
f.readline()
f.close()
 '''
 
"""
n = 4

for i in range(n):
    print (i)
"""

def divides_evenly(a, b):
    bool = False
    if a % b == 0:
        bool = True

    return bool

num = int(input("Enter an integer: "))

def prime_numbers(num):
    
    for i in range(2, num):
        prime = True
        
        for j in range(2, i):
            
            if i % j == 0:
                prime = False
                break
        if prime == True:
            print(i)

'''
a = 3
b = 10
c = 24
result = (b != c) and (not b <= c)
print( result )

'''
    
'''
for i in range(4):
    print(i)

'''


