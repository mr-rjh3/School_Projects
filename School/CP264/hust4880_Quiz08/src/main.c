/*
 ============================================================================
 Name        : project_test.c\
 Author      : Riley Huston
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	MAX_STR_LEN		264
#define MAX_HASH_SIZE	50

typedef struct node{
	int key;
	char *username;
	char *password;
	struct node *link;

}node;

typedef struct h_table{
	node **table;
	int max_size;
	int curr_size;

}h_table;

node *create_node(int key, char* username, char* password){
	node *n = (node *) malloc(sizeof(n));
	n->key = key;
	n->username = malloc(sizeof(username));
	n->username = username;
	n->password = malloc(sizeof(password));
	n->password = password;
	n->link = NULL;

	return n;
}

h_table *create_table(int size){
	h_table *table = (h_table *) malloc(sizeof(table));
	table->curr_size = 0;
	table->max_size = size;
	table->table = calloc(size, sizeof(node)); // Allocates memory like malloc but sets to zero

	return table;
}

int hash(char *value){
	int key = 0;
	for(int i = 0; i < strlen(value); i++)
		key += (int)value[i];
	return key;
}

void insert(char *username, char* password, h_table *hash_t){
	int key = hash(username);
	int index = key % hash_t->max_size;
	node *n = hash_t->table[index];
	node *new_node = create_node(key, username, password);

	if(n == NULL){
		printf("NEW CHAIN --> Index: %d\n", index);
		hash_t->table[index] = new_node;
		hash_t->curr_size++;
	} else{
		printf("CHAIN LINKED- -> Index: %d\n", index);
		while(n != NULL)
			n = n->link;
		n = new_node;

	}
}

char *retrieve_pass(char *username, h_table *hash_t){
	char *password = NULL;
	int key = hash(username);
	int index = key % hash_t->max_size;
	node *n = hash_t->table[index];
	if(n != NULL){
		while(key != n->key && n->link != NULL)
			n = n->link;
		if(n->key == key)
			password = n->password;
	}

	return password;
}

int main(void) {

	setbuf(stdout, NULL);

	FILE* fptr;
	int index = 0;
	char *username;
	char *password;

	char line[MAX_STR_LEN];
	char temp[MAX_STR_LEN];
	int len;
	h_table *hash_t = create_table(MAX_HASH_SIZE);

	fptr = fopen("logins.txt", "r");
	while (fgets(line, MAX_STR_LEN, fptr) != NULL) {
		strcpy(temp, line);
		username = strtok(temp, " ");
		password = strtok(NULL, " ");
		insert(username, password, hash_t);

	}

	scanf("%s", username);
	scanf("%s", password);
	if(retrieve_pass(username, hash_t) != NULL)
		printf("SUCCESS");
	else
		printf("FAILURE");

	for(int i = 0; i < hash_t->max_size; i++){
		node *n = hash_t->table[i];
		printf("%d ------------------------------------\n", i);
		while(n->link != NULL){
			printf("USERNAME: %s\t", n->username);
			printf("PASSWORD: %s\n", n->password);
			printf("---\n");
		}
	}

	return 0;
}
