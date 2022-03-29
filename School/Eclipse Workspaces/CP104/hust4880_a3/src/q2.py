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

midterm_mark = float(input('Enter your score in Midterm (0-100): '))
final_exam_mark = float(input('Enter your score in Final (0-100): '))

exam_score = 0.2 * midterm_mark + 0.4 * final_exam_mark

print('Your weighted exam score is: {:.1f}'.format(exam_score))