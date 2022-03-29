/*
 ============================================================================
 Name        : hust4880_Quiz03_Q1.c
 Author      : Riley Huston
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 	264

int isValid(char msg[MAX_STR_LEN]) {
	int valid = 1;
	int i = 0;
	if (strlen(msg) > 1) {
		while (valid == 1 && i < strlen(msg)) {
			if ((msg[i] <= 'A' && msg[i] >= 'Z')
					|| (msg[i] <= 'a' && msg[i] >= 'z')) {
				valid = 0;
			}
			i++;
		}
	}
	return valid;
}

int main(void) {
	setbuf(stdout, NULL); // Turns standard output buffering off

	char message[MAX_STR_LEN];
	int key;
	printf("Enter a message: ");
	scanf("%[^\n]%*c", message);
	printf("Enter a key: ");
	scanf("%d", &key);

	if (isValid(message) == 1) {
		for (int i = 0; i < strlen(message); i++) {
			if (message[i] != ' ') {
				for (int j = 0; j < key; j++) {
					if (message[i] >= 'A' && message[i] <= 'Z') {
						message[i]++;
						if (message[i] > 'Z') {
							message[i] = 'A';
						}
					} else if (message[i] >= 'a' && message[i] <= 'z') {
						message[i] = message[i] + 1;
						if (message[i] > 'z') {
							message[i] = 'a';
						}
					}

				}
			}
		}
	}
	printf("%s", message);

	return 0;
}
