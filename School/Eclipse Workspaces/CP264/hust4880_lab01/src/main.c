/*
 -------------------------------------
 File:    main.c
 Project: hust4880_lab01
 file description
 -------------------------------------
 Author:  your name here
 ID:      your ID here
 Email:   your Laurier email here
 Version  2020-09-16
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	setbuf(stdout, NULL); // turns standard output buffering off
	int number = 0;
	printf("Enter a number: ");
	scanf("%d", &number);
	printf("The number you entered is %d\n", number);
	return (0);
}
