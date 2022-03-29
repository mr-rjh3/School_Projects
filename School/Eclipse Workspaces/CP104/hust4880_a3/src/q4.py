"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019 09 26"
------------------------------------------------------------------------
"""

def calorie_calculator(fat_grams, carb_grams):
    '''
     -------------------------------------------------------
     Calculates the calories gained from fat and carbs
     Use: cal_from_fat, cal_from_carbs = calorie_calculator(fat_grams, carb_grams)
     -------------------------------------------------------
     Parameters:
     fat_grams - grams of fat consumed (int > 0)
     carb_grams - grams of carbohydrates consumed (int > 0)
     Returns
     cal_from_fat - calories gained from fat consumed (float >= 0)
     cal_from_carbs - calories gained from carbohydrates consumed (float >= 0)
     -------------------------------------------------------
    '''
    cal_from_fat = fat_grams * 9
    cal_from_carbs = carb_grams * 4
    return cal_from_fat, cal_from_carbs


fat_grams = float(input('Enter the fat grams consumed: '))
carb_grams = float(input('Enter the carbohydrate grams consumed: '))

cal_from_fat, cal_from_carbs = calorie_calculator(fat_grams, carb_grams)
total_cal = int(cal_from_carbs + cal_from_fat)

print('Total calories a total of {}[Fat calories:{:.2f} and Carb calories: {:.2f}]'.format(total_cal, cal_from_fat, cal_from_carbs))
