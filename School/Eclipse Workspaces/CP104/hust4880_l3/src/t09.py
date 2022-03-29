"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019 M09 25"
------------------------------------------------------------------------
"""

PI = 3.14

Diameter_base = float(input('Diameter of container base (cm): '))
height = float(input('Height of container (cm): '))
cost = float(input('Cost of material ($/cm^2): '))
containers = float(input('Number of containers: '))

area = (PI*(Diameter_base/2)**2) + ((2*PI*(Diameter_base/2)) * height)
cost_per_container = area * cost
total_cost = cost_per_container * containers
print('The cost of one container is: ${:.2f}'.format(cost_per_container))
print('The total cost of all containers is ${:.2f}'.format(total_cost))
