"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2020-01-15"
------------------------------------------------------------------------
"""

'''
from Set_linked import Set

s = Set()
s.add(1)
s.add(1)
s.add(1)
s.add(1)
s.add(1)
s.add(1)
s.add(2)
s.add(3)
s.add(4)
s.add(5)
s.add(6)
s.add(7)
s.add(8)
s.add(9)
print(len(s))
'''
'''
for i in s:
    print(i)
t1, t2 = s.split_th()
for i in t1:
    print(i)
print()
for i in t2:
    print(i)
'''

from Popularity_Tree_linked import Popularity_Tree


pt = Popularity_Tree()

pt.insert(11)
pt.insert(7)
pt.insert(15)
pt.insert(6)
pt.insert(9)
pt.insert(12)
pt.insert(18)
pt.insert(8)

pt.retrieve(11)
pt.retrieve(11)
pt.retrieve(11)
pt.retrieve(11)
print(pt.is_valid())
print(pt.preorder())
pt.retrieve(9)
print(pt.preorder())
#print(node._value, node._rcount)



print(pt.is_valid())



'''from Sorted_List_linked import Sorted_List

l = Sorted_List()
l2 = Sorted_List()

l.insert(1)
l.insert(2)
l.insert(3)
l.insert(4)


l2.insert(3)
l2.insert(4)
l2.insert(5)
l2.insert(6)


l1 = Sorted_List()
l1.intersection(l, l2)
current = l1._front

while(True):
    print(current._value)
    current = current._next
'''


'''
from List_linked import List

s = List()
l = List()
t = List()
l.append(1)
l.append(2)
l.append(3)
l.append(4)
t.append(1)
t.append(2)
t.append(3)
t.append(4)


s.union_r(l, t)
'''
'''

fv = open('foods.txt', 'r')
foods = read_foods(fv)
fv.close()

#queue_test(foods)

list_test(foods)

'''
#print(food_table(foods))
'''
source = [1,2,3,4,5]
stack_test(source)

'''
'''
f = get_food()
print(f)
'''

'''
f = []
f.append(Food('Spanakopita',5,True,260))
f.append(Food('Span',4,False,1100))
f.append(Food('soloa',6,True,260))

food_table(f)

'''


'''
line = 'Spanakopita|5|True|260'
foods = []
food = line.split('|')
print(food)

if(food[2].lower == 'true'):
    food[2] = True
elif(food[2].lower == 'false'):
    food[2] = False
#if(len(food) == 4 and food[2] == True or food[2] == False):
foods.append(Food(food[0], int(food[1]), food[2], int(food[3])))
print(foods)'''