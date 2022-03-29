/*
 ============================================================================
 Name        : hust4880_quiz01.c
 Author      : Riley Huston
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	/*
	 Question 1:
	 Write a program to perform addition, subtraction, division, integer division,
	 multiplication, and modulo division on two integer numbers.
	 */

	int a = 0, b = 0;
	setbuf(stdout, NULL); // turns standard output buffering off

	printf("Enter the first number: ");
	scanf("%d", &a); // scans for input for number 'a'
	printf("Enter the second number: ");
	scanf("%d", &b); // scans for input for number 'b'
	printf("%d + %d = %d\n", a, b, a + b); // Addition
	printf("%d - %d = %d\n", a, b, a - b); // Subtraction
	printf("%d x %d = %d\n", a, b, a * b); // Multiplication
	printf("%d / %d = %d (Integer Division)\n", a, b, a / b); // Integer division
	printf("%d %% %d = %d (Modulo Division)\n", a, b, a % b); // Modulo division
	printf("%d / %d = %.2f (Normal Division)\n", a, b, (float) (a / b)); // Normal division

	return 0;
}
