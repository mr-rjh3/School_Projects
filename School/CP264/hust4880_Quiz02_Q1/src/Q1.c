/*
 ============================================================================
 Name        : hust4880_Quiz02_Q1.c
 Author      : Riley Huston
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int MAX_SIZE = 264;

int main(void) {
	setbuf(stdout, NULL);           // turns standard output buffering off
	char str[MAX_SIZE];

	// User input for string
	printf("Enter a string: ");
	scanf("%s", str);

	// Variables
	int str_size = strlen(str);
	char unique_letters[str_size];
	int unique_letters_index = 0;
	int letter_count[str_size];
	bool is_unique = true;

	for (int i = 0; i < str_size; i++) { // Loop through user input
		for (int j = 0; j < strlen(unique_letters); j++) { // Loop through all unique letters
			if (str[i] == unique_letters[j]) { // If current string letter is equal to a unique letter
				is_unique = false;	// is not unique
				letter_count[j]++;// Increments letter count for given letter by 1
				j = strlen(unique_letters); // exit for loop by making j equal to the length of unique letters
			}
		}
		if (is_unique) { // checks to see if given letter is unique
			unique_letters[unique_letters_index] = str[i];// If unique, is entered into unique letters array
			letter_count[unique_letters_index] = 1;	// Makes count for letter 1 as it is the first occurrence
			unique_letters_index++;	// Increments unique letter index by one
		}
		is_unique = true; // Resets boolean to true for next loop

	}
	// Prints unique letters and letter count
	for (int i = 0; i < unique_letters_index; i++) {
		printf("%c   %d \n", unique_letters[i], letter_count[i]);
	}

	return 0;
}
