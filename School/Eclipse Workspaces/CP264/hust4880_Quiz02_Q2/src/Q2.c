/*
 ============================================================================
 Name        : hust4880_Quiz02_Q2.c
 Author      : Riley Huston
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int* arrayMin(int *array, int n) {
	if (n > 0) { // If size is not 0
		int min = 0; // Min index is equal to 0
		for (int i = 0; i < n; i++) { // For loop for all values in array
			if (array[i] < array[min]) { // If array at index 'i' is less than array at index 'min'
				min = i; // Make min equal to i
			}
		}
		return array + min; // Returns Array + index of min number
	} else {
		return NULL; // If empty array returns NULL
	}

}

void doTest(int *array, int n) {
	printf("arrayMin(");
	if (array == NULL) {
		printf("NULL");
	} else {
		printf("{");
		for (int i = 0; i < n; i++) {
			printf("%d", array[i]);
			if (i < n - 1) {
				printf(", ");
			}
		}
		printf("}");
	}
	printf(", %d) is \n", n);
	int *p = arrayMin(array, n);
	if (p == NULL) {
		printf("NULL\n");
	} else {
		printf("%d\n", *p);
	}
}

int main(void) {
	int array1[] = { 77, 33, 19, 99, 42, 6, 27, 4 };
	int array2[] = { -3, -42, -99, -1000, -999, -88, -77 };
	int array3[] = { 425, 59, -3, 77, 0, 36 };

	doTest(array1, 8);
	doTest(array2, 7);
	doTest(array3, 6);
	doTest(NULL, 0);
	doTest(array1, 0);

	return EXIT_SUCCESS;
}

