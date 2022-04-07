/*
 ============================================================================
 Name        : hust4880_Quiz03_Q2.c
 Author      : Riley Huston
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN	264

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
	setbuf(stdout, NULL); // turns standard output buffering off

	int key = 5;
	char f_msg[MAX_STR_LEN];
	char encryption[MAX_STR_LEN] = "";
	char *filename = "encMessage.txt";
	FILE *fp;

	fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("Could not open file %s", filename);
		return 1;
	}
	while (fscanf(fp, "%s", &f_msg) != EOF) {
		strncat(encryption, f_msg, MAX_STR_LEN);
		strncat(encryption, " ", MAX_STR_LEN);
	}
	fclose(fp);

	if (isValid(encryption) == 1) {
		for (int i = 0; i < strlen(encryption); i++) {
			if (encryption[i] != ' ') {
				for (int j = 0; j < key; j++) {
					if (encryption[i] >= 'A' && encryption[i] <= 'Z') {
						encryption[i]--;
						if (encryption[i] < 'A') {
							encryption[i] = 'Z';
						}
					} else if (encryption[i] >= 'a' && encryption[i] <= 'z') {
						encryption[i]--;
						if (encryption[i] < 'a') {
							encryption[i] = 'z';
						}
					}
				}
			}
		}
	}
	printf("%s", encryption);

	return 0;
}
