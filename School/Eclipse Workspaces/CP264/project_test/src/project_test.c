///*
// ============================================================================
// Name        : project_test.c\
// Author      : Riley Huston
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
// ============================================================================
// */
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define MAX_STR_LEN 	10
//
///*
// * Priority Queue node that can store a tree
// * Sorted by frequency
// */
//typedef struct t_node {
//	char value;                 		///< Data stored in the node.
//	int frequency;						///< Frequency of data.
//	struct h_node *left;                  ///< Pointer to the left child.
//	struct h_node *right;                 ///< Pointer to the right child.
//} t_node;
//
//typedef struct h_tree {
//	h_node *root;                 		///< Data stored in the node.
//	int count;		///< Count of next nodes (does not include left and right).
//} h_tree;
//
//typedef struct list_node {
//	char value;							///<Data stored in node
//	int frequency;						///<Frequency of value
//	struct list_node *next;				///<Pointer to next node
//} list_node;
//
//typedef struct list {
//	list_node *head;					///< Head of list
//	int count;							///< Count of nodes in list
//} list;
//
//typedef struct table_node {
//	char *value;                 		///< Character index.
//	char binary[MAX_STR_LEN];			///< Binary representation of character.
//	struct table_node *next;			///<Pointer to next node
//} table_node;
//
//typedef struct table {
//	table_node *head;                 	///< Head of the table.
//	int count;							///< Number of unique characters.
//} table;
//
//h_node* create_node(char value);
//h_node* node_combine(h_node *left, h_node *right);
//void insert_node(h_node *head, h_node *new_node);
//
//char* decode(t_node* root, FILE* input);
//char* get_encoded_msg(FILE* input);
//
//
//
//char* decode(t_node* root, FILE* input){
//	char encoded_msg[MAX_STR_LEN] = get_encoded_msg(input);	// Gets encoded message from input file using helper function
//
//	char decoded_msg[MAX_STR_LEN];
//	t_node* current = root;	// Sets current to root, used for traversal
//
//	for(int i = 0; i < strlen(encoded_msg); i++){	// For loop which traverses each binary character in encoded message
//
//		switch(encoded_msg[i]){	// Switch case for encoded message
//			case "1":	// If '1' current traverses right down the tree
//				current = current->right;
//				break;
//			case "0":	// If '0' current traverses left down the tree
//				current = current->left;
//				break;
//		}
//
//		if(current->left == NULL || current->right == NULL){	// After going down tree check if NULL is the new current's left or right child
//			strcat(decoded_msg, current->value);	// If left or right is NULL we have found a leaf which contains a letter
//			current = root;	// Return current to root to continue decoding process
//		}
//
//	}
//	return decoded_msg;	// Return fully decoded message
//}
//
//int main(void) {
//
//	FILE *input;
//	FILE *output;
//
//	input = fopen("input.txt","r");
//	output = fopen("output.txt","w");
//
//
//
//	fclose(input);
//	fclose(outpu);
//
//
//
//
//	return 0;
//}
