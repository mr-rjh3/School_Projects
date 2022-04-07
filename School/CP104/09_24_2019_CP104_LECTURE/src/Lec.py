"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019 M09 24"
------------------------------------------------------------------------
"""
#--------------------------------------------
#Prog 11. [Commenting, Split()], Copy
#--------------------------------------------
'''
import math
def computeKineticEnergy(mass, velocity):
    """
    -------------------------------------------------------
    Calculates Kinetic Energy for a given mass and velocity
    Use: kineticEnergy = computeKineticEnergy (mass, velocity)
    -------------------------------------------------------
    Parameters:
        mass             - mass of the object (int > 0)
        velocity         - velocity of the object (int > 0)
    Returns
        kineticEnergy     - Kinetic energy of the object (float >= 0)
    -------------------------------------------------------
    """

    kineticEnergy=(0.5) * mass * (math.pow(velocity, 2))
    return kineticEnergy

def computePotentialEnergy(mass, gravitationalAcceleration, height):
    """
    -------------------------------------------------------
    Calculates the potential energy of an object
    Use: potentialEnergy = computePotentialEnergy(mass, gravitationalAcceleration, height)
    -------------------------------------------------------
    Parameters:
        mass                         - mass of the object (float > 0)
        gravitationalAcceleration     - gravitation acc of the object (int > 0)
        height                         - third quiz score (int > 0)
    Returns
        potentialEnergy             - potential energy of the object (float >= 0)
    -------------------------------------------------------
    """

    potentialEnergy=(mass * gravitationalAcceleration * height)
    return potentialEnergy

def main():
    mass,velocity=input("Enter the mass and velocity for kinetic energy:").split()
    mass = int(mass)
    velocity = int(velocity)

    ke = computeKineticEnergy(mass,velocity)
    print ("The kinetic energy is: {:.2f}".format(ke))

    mass =                             float( input("Enter the mass for calculating potential energy:") )
    gravitationalAcceleration =     int( input("Enter the gravtitational acceleration for calculating potential energy:") )
    height =                         int( input("Enter the height for calculating potential energy:") )
    
    pe = computePotentialEnergy(mass,gravitationalAcceleration,height)
    print ("The potential energy is: {:.2f}".format(pe) )
    
main()
'''

#--------------------------------------------
#Prog 12. [Scope, Local Variable], What is the output?
#--------------------------------------------
'''
def subtraction (operand1, operand2):
    result = operand2 - operand1
    return result

def main ():
    op1 = 5.2222
    op2 = 2.2222

    sub = subtraction(op1, op2)
    print("{0:.2f} - {1:.2f} = {2:.2f}".format(op2, op1, sub))


main()
'''

#--------------------------------------------
#Prog 13. [Scope, Local Variable], What is the output?. VisTool
#--------------------------------------------
'''
def main ():
    op1 = 5.2222
    op2 = 2.2222
    
    result = subtraction(op1, op2)
    print("{0:.2f} - {1:.2f} = {2:.2f}".format(op2, op1, result))
    
    result = addition(op1, op2)
    print("{0:.2f} - {1:.2f} = {2:.2f}".format(op2, op1, result))
    
def subtraction (operand1, operand2):
    result = operand2 - operand1
    print("Result log from subtraction: ", result)
    return result
    
def addition (operand1, operand2):
    result = operand2 + operand1
    print("Result log from addition: ", result)
    return result
    
main()
'''
#--------------------------------------------
#Prog 14. [Scope, Global Variable], What is the output?. VisTool
#--------------------------------------------
'''
result  = 0
def main ():
    op1 = 5.2222
    op2 = 2.2222

    result = operation(op1, op2)
    print("{0:.2f} - {1:.2f} = {2:.2f}".format(op2, op1, result))

def operation (operand1, operand2):
    result = -operand2 - operand1
    return result
main()

print("Result Log: ", result)
'''

#--------------------------------------------
#Prog 15. [Resctrict Use Of Global Variable], What is the output?. VisTool
#--------------------------------------------
'''
result  = 0
def main ():
    op1 = 5.2222
    op2 = 2.2222

    result = operation(op1, op2)
    print("{0:.2f} - {1:.2f} = {2:.2f}".format(op2, op1, result))

def operation (operand1, operand2):
    global result 
    result = -operand2 - operand1
    return result
main()

print("Result Log: ", result)
'''

#--------------------------------------------
#Prog 16. [Global Variable for CONSTANTS], Copy. Code copied from book
#--------------------------------------------
'''
# The following is used as a global constant to represent the contribution rate.
CONTRIBUTION_RATE = 0.05

def main():
    gross_pay = float(input('Enter the gross pay: '))
    bonus = float(input('Enter the amount of bonuses: '))
    show_pay_contrib(gross_pay)
    show_bonus_contrib(bonus)

# The show_pay_contrib function accepts the gross pay as an argument and displays the retirement contribution for that amount of pay.
def show_pay_contrib(gross):
    contrib = gross * CONTRIBUTION_RATE
    print('Contribution for gross pay: $', format(contrib, ',.2f'), sep='')

# The show_bonus_contrib function accepts the bonus amount as an argument and displays the retirement contribution for that amount of pay.
def show_bonus_contrib(bonus):
    contrib = bonus * CONTRIBUTION_RATE
    print('Contribution for bonuses: $', format(contrib, ',.2f'), sep='')

# Call the main function.
main()

'''
#--------------------------------------------
#Prog 17. [returning multiple values], copy
#--------------------------------------------
'''
CONTRIBUTION_RATE = 0.05
def inputData():
    name, university = input("Enter your name and university: ").split()
    pay = int(input("Enter your pay: "))
    return name, university, pay

def show_pay_contrib(gross):
    contrib = gross * CONTRIBUTION_RATE
    return contrib
    

def main(): 
    name, univ, pay = inputData()
    contrib = show_pay_contrib(pay)
    print('Contribution for gross pay: ${}'.format(contrib, ',.2f'), sep='')
main()
'''

# Develop a calculator. You can work in groups of five. 
# - More functionality
# - Better Usability
# - Understandable code
# - Comments









