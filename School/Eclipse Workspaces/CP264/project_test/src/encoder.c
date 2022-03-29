/*
------------------------------------------------------------------------------------------
File:    encoder.c
Project: huffmanTree
Purpose: Huffman Tree Group Project
==========================================================================================
Program Description:
Encodes the message in input.txt into output.txt and records the tree into
tree.txt
------------------------------------------------------------------------------------------
Author:  Shailendra Singh, Riley Huston,
ID:      190777790,
Email:   sing7779@mylaurier.ca,
Version  2020-11-30
------------------------------------------------------------------------------------------
*/

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constants
#define MAX_BINARY_LEN 	10
#define MAX_STR_LEN		264

//Structures--------------------------------------------------------------------------------------------------------------------------

//Table
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


//Functions to be in main:-----------------------------------------------------------------------------------------------------------

/*
PURPOSE
Will take  pointer to file with input.txt, allocate memory for and create a table in
the given table pointer and record all the characters and frequencies into
created table

PARAMETERS
FILE* input: Input file with text to be encoded
table* t: Table pointer which will store the frequencies and unique characters

RETURN
Pointer to table with characters and frequencies. All binary strings are empty strings.
The table is the same table
*/
table* convert_to_table(FILE* input, table* t); // Tatiana

/*
PURPOSE
Takes the characters and frequencies in table, puts them as pq nodes and then inserts
them into the pq.

PARAMETERS
table* t: The table with characters and frequencies

RETURN
Pointer to finished priority queue
*/
pq* table_to_queue(table* t); // Christine

/*
PURPOSE
Converts PQ into a PQ with one node that contains the
completed huffman

PARAMETERS
pq* main: Priority queue to be transform.

RETURN
Root of the completed tree
*/
tree_node* huffman_process(pq* main); //Adam

/*
PURPOSE
Traverses through tree, determines the binary value of each character
and inserts the unique binary code into the given table.

PARAMETERS
tree_node* huffman_root: Pointer to the root of the huffman tree.
table* t: Pointer to the table that will have the binary code recorded for each
unique character.

RETURN
N/A
*/
void insert_binary_to_table(tree_node* huffman_root, table* t); // Ian

/*
PURPOSE
Encode the text from "input" using the table into binary and write that into "output".

PARAMETERS
table* t: The table containing the unique characters with their binary representations
FILE* input: Pointer to file with the text to be encoded.
FILE* output: File where binaries will be written.

RETURN
N/A
*/
void encode(table* t, FILE* input, FILE* output); // Riley

//Helper Functions-----------------------------------------------------------------------------------------------------------------------

/*
PURPOSE
Allocates memory for and creates empty table

RETURN
Pointer to created empty table
*/
table* create_table(); //Shailendra (COMPLETE)

/*
PURPOSE
Allocates memory for and creates a table node

PARAMETERS
char value: Character to be placed in node and table.
int freq: Frequency of character "value"

RETURN
Pointer to created node.
*/
table_node* create_table_node(char value, int freq); //Shailendra (COMPLETE)

/*
PURPOSE
Allocates memory for new tree node and creates it with given data.

PARAMETERS
char value: Character to be stored in tree node
int frequency: Frequency of character "value"
tree_node* left: Pointer to left child of new node
tree_node* right: Pointer to right child of new node

RETURN
Pointer to new tree node.
*/
tree_node* newNode(char value, int frequency, tree_node *left, tree_node *right); //Adam

/*
PURPOSE
Compares two tree nodes and checks which one is smaller, greater or
if they are equal.

PARAMETERS
tree_node* n1: First node
tree_node* n2: Second node

RETURN
If n1 < n2: -1
If n2 < n1: 1
If n2 = n1: 0
*/
int node_compare(tree_node* n1, tree_node* n2); //Adam

/*
PURPOSE
Takes nodes n1 and n2, adds their frequencies and creates a node
with the value set as NULL, frequency set as the sum and left child set
as n1 and right child set as n2. (IMPORTANT: n1 < n2)

PARAMETERS
tree_node* n1: Node to be left child of parent
tree_node* n2: Node to be right child of parent

RETURN
Parent node with n1 and n2 as their children with the sum of their frequencies
as the frequency of the parent.
*/
tree_node* node_combine (tree_node *n1, tree_node *n2); //Adam

/*
PURPOSE
Inserts node into priority queue in proper order

PARAMETERS
pq* pq_main: Priority queue
pq_node*: node: Node to be inserted into priority
queue

RETURN
if node is inserted, then return 1
if node is not inserted, then return 0
*/
int pq_insert(pq* pq_main, pq_node* node); //Adam

/*
PURPOSE
Creates a new priority queue node
PARAMETERS
pq* pq_main: Priority queue
pq_node*: node: Node to be inserted into priority
queue

RETURN
if node is inserted, then return 1
if node is not inserted, then return 0
*/
pq_node* newPQNode();


//Function Code---------------------------------------------------------------------------------------------------------------------------------------


tree_node* newNode(char value, int frequency, tree_node *left, tree_node *right)
{
    tree_node* node = malloc(sizeof(tree_node));
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}

int node_compare(tree_node *n1, tree_node *n2) {
    int rtrn;
    if (n1->frequency > n2->frequency) {
        rtrn = 1;
    }
    else if (n1->frequency < n2->frequency) {
        rtrn = -1;
    }
    else {
        rtrn = 0;
    }
    return rtrn;
}

tree_node* node_combine (tree_node *n1, tree_node *n2) {
    return(newNode(NULL, (n1->frequency + n2->frequency), n1, n2));
}

pq_node* newPQNode() { //creates a new priority queue node

    pq_node* node = malloc(sizeof(pq_node));
    node->next = NULL;
    node->ptr = NULL;
    return node;
}

int pq_insert(pq* pq_main, pq_node* node) {

    //return 1 on successful insert, 0 on no insert
    pq_node* prev = NULL;
    pq_node* curr = pq_main->head;
    int inserted = 0;
    if (curr == NULL) { //pq is empty, insert and set head to node
        pq_main->head = node;
    }
    else { //pq is not empty; iterate through the pq
        while (curr != NULL && inserted == 0) {
            tree_node* t_node1 = curr->ptr;
            tree_node* t_node2 = node->ptr;


            if (node_compare(t_node1, t_node2) != -1 ) { // node has higher or equal freq than curr; iterate
                prev = curr;
                curr = curr->next;
            }
            else { // node to be inserted has lower frequency than curr; insert
                if (prev == NULL) { // node is smallest in the pq
            node->next = pq_main->head;
            pq_main->head = node;
        }
        else { // node is not the smallest
            prev->next = node;
            node->next = curr;
        }
        inserted = 1;
            }
        }
    }
    return inserted;
}

tree_node* huffman_process(pq* pq_main) { // takes the priority queue as input, outputs the root of the completed Huffman Tree
    pq_node* smallest = pq_main->head;
    pq_node* second_smallest = smallest->next;
    while(smallest->next != NULL) {
        pq_main->head = second_smallest->next; //set the new front to the 3rd smallest

        tree_node* combined_node = node_combine(smallest->ptr, second_smallest->ptr); //create an interior node with combined frequencies

        pq_node* new_pq_node = newPQNode();
        new_pq_node->next = NULL;
        new_pq_node->ptr = combined_node;

        pq_insert(pq_main, new_pq_node); // put the new pq node pointing at the new interior node into the pq

        pq_node* smallest = pq_main->head;
        pq_node* second_smallest = smallest->next;
    }
    return smallest->ptr; // this is the root of the completed Huffman Tree
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

//NEW Function Code---------------------------------------------------------------------------------------------------------------------------------------

/*
void encode(table* t, FILE* input, FILE* output){ // Made by Riley
	char character;
	table_node* current = t->head;	// Sets current to table head, used for traversal
	while ((character = fgetc(input)) != EOF)	// While loop which traverses the input message character by character
	{
		while(current != NULL && current->value != character)	// While loop which traverses table until the character is found or current is NULL
			current = current->next;
		if(current != NULL)	// If current is not NULL we have the letter in the table and write the binary representation of it to the output file
			fprintf(output, "%s", current->binary);
		else // If current is NULL we have an error as the letter to encode is not the table, thus we print an error message
			printf("ERROR --> Unable to find letter in given table");
	}
}
*/

void encode(table* t, FILE* input, FILE* output){ // Made by Riley
	char character;
	table_node* current = t->head;	// Sets current to table head, used for traversal
	while ((character = fgetc(input)) != EOF)	// While loop which traverses the input message character by character
	{
		while(current != NULL && current->value != character)	// While loop which traverses table until the character is found or current is NULL
		{
			printf("\n--%c ", current->value);
			printf("%d ", current->frequency);
			printf("%s", current->binary);
			current = current->next;
		}
		if(current != NULL){	// If current is not NULL we have the letter in the table and write the binary representation of it to the output file
			fprintf(output, "%s", current->binary);
			printf("SUCCESS --> Printed '%c' to file!\n", character);
		}
		else{ // If current is NULL we have an error as the letter to encode is not the table, thus we print an error message
			printf("\nERROR --> Unable to find letter in given table: %c \n", character);
		}
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
                break;
            case '0':    // If character is '0' current traverses left down the tree
                current = current->left;
                break;
            default:	// If character is neither '1' or '0' we print an error message
            	printf("ERROR --> Non binary character");
            	break;
        }
        if(current->left == NULL || current->right == NULL){    // After going down tree check if NULL is the new current's left or right child
            fprintf(output, "%c", binary_char);    // If left or right is NULL we have found a leaf which contains a letter thus we write it to the file
            current = root;    // Return current to root to continue decoding process
        }
    }
}


//Main Code---------------------------------------------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    //Turns standard output buffering off
    setbuf(stdout, NULL);

    //Open input file
    FILE* input = fopen("input.txt", "r");

    //Initialize table
    table* valueTable;

    //Put file values in table
    valueTable = convert_to_table(input, valueTable);

    //Convert table into priority queue
    pq* huffmanQueue = table_to_queue(valueTable);

    //Perform huffman process on queue and return pointer to tree
    tree_node* huffmanTree = huffman_process(huffmanQueue);

    //Traverse through tree and put binary values for each char in the table
    insert_binary_to_table(huffmanTree, valueTable);

    //Create output and tree file
    FILE* output = fopen("output.txt", "w");
    FILE* tree = fopen("tree.txt", "w");

    //Encode the input message into output.txt using the binaries from table and records the tree into tree.txt
    encode(valueTable, input, output);

    //Close file pointers
    fclose(input);
    fclose(output);
    fclose(tree);

    //Return Statement
    return 0;

}
