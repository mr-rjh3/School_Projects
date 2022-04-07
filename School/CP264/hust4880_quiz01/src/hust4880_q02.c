/*
 -------------------------------------
 File:    hust4880_q02.c
 Project: hust4880_quiz01
 file description
 -------------------------------------
 Author:  your name here
 ID:      your ID here
 Email:   your Laurier email here
 Version  2020-09-21
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	/*
	 Question 2
	 Write a program to take input from the user and then check whether it is a number or a character.
	 If it is a character, determine whether it is in upper case or lower case
	 */

	char c;
	setbuf(stdout, NULL); // turns standard output buffering off

	printf("Enter any character: ");
	scanf(" %c", &c); // User input

	if (c >= 'a' && c <= 'z') { // Compares input for lower case letters
		printf("Lower case character was entered: %c", c);
	} else if (c >= 'A' && c <= 'Z') { // Compares input for upper case letters
		printf("Upper case character was entered: %c", c);

	} else if (c >= '0' && c <= '9') { // Compares input for numbers
		printf("A number was entered : %c", c);

	} else { // If input it neither character or number
		printf("You did not enter a character or number");
	}

	return 0;
}
