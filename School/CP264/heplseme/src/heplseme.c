/*
 ============================================================================
 Name        : heplseme.c
 Author      : Riley Huston
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_BINARY_LEN		10

typedef struct table_node
{
    char value;                           ///< Character index.
    char binary[MAX_BINARY_LEN];          ///< Binary representation of character.
    int frequency;                        ///< Frequency of value
    struct table_node* next;              ///< Pointer to next node
} table_node;

typedef struct table
{
    table_node* head;                     ///< Head of the table.
    int count;                            ///< Number of unique characters.
} table;

// A Huffman tree node
typedef struct tree_node
{
    char value;                           ///< Character stored in node
    int frequency;                        ///< Frequency of character value
    struct tree_node* left;                  ///< Pointer to the left child.
    struct tree_node* right;                 ///< Pointer to the right child.
} tree_node;

//Priority Queue
typedef struct pq
{
    struct pq_node* head;                 ///< Head of the priority queue
}pq;

typedef struct pq_node
{
    struct tree_node* ptr;                ///< Pointer to tree within node
    struct pq_node* next;                 ///< Pointer to next pq node
} pq_node;




void encode(table* t, FILE* input, FILE* output){ // Made by Riley
	char character;
	table_node* current = t->head;	// Sets current to table head, used for traversal
	while ((character = fgetc(input)) != EOF)	// While loop which traverses the input message character by character
	{
		while(current != NULL && current->value != character)	// While loop which traverses table until the character is found or current is NULL
			current = current->next;
		if(current != NULL){	// If current is not NULL we have the letter in the table and write the binary representation of it to the output file
			fprintf(output, "%s", current->binary);
			printf("SUCCESS --> Printed '%c' to file!\n", character);
		}
		else // If current is NULL we have an error as the letter to encode is not the table, thus we print an error message
			printf("\nERROR --> Unable to find letter in given table: %c \n", character);
		current = t->head;
	}
}

void decode(tree_node* root, FILE* input, FILE* output){ // Made by Riley
	char binary_char;
    tree_node* current = root;    // Sets current to root, used for traversal

    while((binary_char = fgetc(input)) != EOF){    // While loop which traverses each binary character in encoded message
        switch(binary_char){    // Switch case for encoded message
            case '1':    // If character is '1' current traverses right down the tree
                current = current->right;
                printf("TRAVERSE RIGHT\n");
                break;
            case '0':    // If character is '0' current traverses left down the tree
                current = current->left;
                printf("TRAVERSE LEFT\n");
                break;
            default:	// If character is neither '1' or '0' we print an error message
            	printf("ERROR --> %c is a non binary character\n", binary_char);
            	break;
        }
        if(current->left == NULL || current->right == NULL){    // After going down tree check if NULL is the new current's left or right child
            fprintf(output, "%c", binary_char);    // If left or right is NULL we have found a leaf which contains a letter thus we write it to the file
            current = root;    // Return current to root to continue decoding process
        }
    }
}

table* create_table()
{
    //Allocate memory for table
    table* valueTable = (table*) malloc(sizeof(table));

    //Return table pointer
    return valueTable;
}

table_node* create_table_node(char value, int freq)
{
    //Allocate memory for a table node
    table_node* newNode = (table_node*) malloc(sizeof(table_node));

    //Initialize data
    newNode->value = value;
    newNode->frequency = freq;
    newNode->binary[0] = '\0';
    newNode->next = NULL;

    //Return new pointer
    return newNode;
}


int main(void) {
	setbuf(stdout, NULL);
	tree_node* root = malloc(sizeof(root));
	table* t = create_table();

	table_node* node = create_table_node('a', 3);
	node->binary[0] = '1';
	node->binary[1] = '1';
	t->head = node;

	table_node* node2 = create_table_node('b', 3);
	node2->binary[0] = '0';
	node2->binary[1] = '0';
	t->head->next = node2;

	table_node* node3 = create_table_node(' ', 2);
	node3->binary[0] = '1';
	node3->binary[1] = '0';
	t->head->next->next = node3;

	table_node* node4 = create_table_node('c', 1);
	node4->binary[0] = '0';
	node4->binary[1] = '1';
	t->head->next->next->next = node4;
	table_node* curr = t->head;

	while(curr != NULL){
		printf("%c ", curr->value);
		printf("%d ", curr->frequency);
		printf("%s\n", curr->binary);
		curr = curr->next;

	}


	FILE *input;
	FILE *output;
	FILE *output2;
	input = fopen("input.txt","r");
	output = fopen("output.txt","w");
	output2 = fopen("output2.txt","w");
	if (input == NULL)
	{
		printf("File is not available \n");
	} else{
		encode(t,input,output);
		fclose(output);
		output = fopen("output.txt","r");
		//decode(output,output2);
	}
	fclose(input);
	fclose(output);
	fclose(output2);




	return 0;
}
