/*
---------------------------------------------------------------------------------------------------------------------------
File:    huffmanProject.c
Project: huffmanTree
Purpose: Huffman Tree Group Project
===========================================================================================================================
Program Description:
Encodes a message from .txt file into binary, records this in a .dat file and decodes back into another .txt file.
---------------------------------------------------------------------------------------------------------------------------
Author:  Shailendra Singh, Riley Huston, Tatiana Olenciuc, Adam Scott, Christine Nguyen
ID:      190777790, 190954880, 191001870, 190600780, 180657710
Email:   sing7779@mylaurier.ca, hust4880@mylaurier.ca,  olen1870@mylaurier.ca, scot0780@mylaurier.ca, nguy7710@mylaurier.ca
Version  2020-11-30
---------------------------------------	------------------------------------------------------------------------------------
NOTE:
The program's structure/design was a team effort. We all decided as a group what algorithms/structs/data structures would be
used, the function declarations and how the functions would be arranged to make the program work. We then assigned functions
for each group member to program on our own. Each of us put our names next to the functions we did. We then put it all
together and debugged the program as a group until, there were no errors.

HOW TO USE:
The filename you type in to encode should be in the local directory and have the file extension.

Example:
Enter file name you would like to encode: LesMiserables.txt

The binary will be in encodeOutput.dat
The decoded file will be in decodeOutput.txt

LIMITS:
Since the frequency of characters is stored in an int type, the most a single character can repeat itself is 2,147,483,647
times. Anymore than that and it will break. This is an enormous number and most probably will not be in test but, is worth
mentioning here.
---------------------------------------------------------------------------------------------------------------------------
*/

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>         // For clock_t, clock(), CLOCKS_PER_SEC

//Constants
#define MAX_BINARY_LEN 20 //Compressing Les Miserables needed at minimum, MAX_BINARY_LEN = 12. Set to 20 to be safe

//Structures---------------------------------------------------------------------------------------------------------------

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
    struct tree_node* left;               ///< Pointer to the left child.
    struct tree_node* right;               ///< Pointer to the right child.
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


//Functions to be in main:-------------------------------------------------------------------------------------------------

/*
 PURPOSE
 Will take  pointer to file with input.txt, allocate memory for and create a table
 and record all the characters and frequencies intocreated table

 PARAMETERS
 FILE* input: Input file with text to be encoded

 RETURN
 Pointer to table with characters and frequencies. All binary strings are empty strings.
 The table is the same table
 */
table* convert_to_table(FILE *input); //Tatiana

/*
PURPOSE
Takes the characters and frequencies in table, puts them as pq nodes and then inserts
them into the pq.

PARAMETERS
table* t: The table with characters and frequencies

RETURN
Pointer to finished priority queue
*/
pq* table_to_queue(table* t); //Christine

/*
PURPOSE
Converts PQ into a PQ with one node that contains the
completed huffman tree

PARAMETERS
pq* main: Priority queue to be transformed.

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
char* binaryString: String that will accumulate binary digits to be inserted into table

RETURN
N/A
*/
void insert_binary_values_into_table(tree_node* huffman_root, table* t, char* binaryString); //Shailendra

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
void encode(table* t, FILE* input, FILE* output); //Riley

/*
PURPOSE
Takes the tree root, the pointer to the binary and the pointer to the output file and decodes the binary file into the
output file.

PARAMETERS
tree_node* root: Root of huffman tree
FILE* input: Pointer to binary data file to be decoded
FILE* output: Pointer to txt file that will have decoded message written into.

RETURN
N/A
*/
void decode(tree_node* root, FILE* input, FILE* output); //Riley

//Helper Functions---------------------------------------------------------------------------------------------------------

/*
PURPOSE
Allocates memory for and creates empty table

RETURN
Pointer to created empty table
*/
table* create_table(); //Shailendra

/*
PURPOSE
Allocates memory for and creates a table node

PARAMETERS
char value: Character to be placed in node and table.
int freq: Frequency of character "value"

RETURN
Pointer to created node.
*/
table_node* create_table_node(char value, int freq); //Shailendra

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
If n1 > n2: 1
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
Creates and allocate memory for new PQ node.

RETURN
The new PQ node
*/
pq_node* newPQNode(); //Adam

/*
PURPOSE
Traverses table to search for entry with input character

RETURN
Table node with character. NULL if character is not found
*/
table_node* search_for_table_node(char character, table *t); //Tatiana

/*
PURPOSE
Allocates memory for and creates new Priority Queue

RETURN
Pointer to priority queue
*/
pq* new_pq (); //Adam

//Code---------------------------------------------------------------------------------------------------------------------
//Shailendra
int main(int argc, char *argv[])
{
    //Turns standard output buffering off
    setbuf(stdout, NULL);

    //Prompt for file name in project
    char file_name[264];
    printf("Enter file name you would like to encode: ");
    scanf("%s", file_name);

    //To store execution time of code
    double timeSpent = 0.0;

    //Start clock
    clock_t beginTime = clock();

    //Open input file
    FILE* encodeInput = fopen(file_name, "r");

    //Crash program if file was not found
    if(encodeInput == NULL)
    {
        printf("NO FILE FOUND");
        exit(0);
    }

    //Initialize table
    table* valueTable;

    //Put file values in table
    valueTable = convert_to_table(encodeInput);

    //Calculate number of unique characters
    int uniqueCharacters = valueTable->count;

    //Print number of unique characters
    printf("Unique Characters: %d\n", uniqueCharacters);

    //Reopen input file
    fclose(encodeInput);
    encodeInput = fopen(file_name, "r");

    //Convert table into priority queue
    pq* huffmanQueue = table_to_queue(valueTable);

    //Perform huffman process on queue and return pointer to tree
    tree_node* huffmanTree = huffman_process(huffmanQueue);

    //Special case (Only 1 unique character)
    if(uniqueCharacters == 1)
    {
        huffmanTree = node_combine(newNode(NULL, 0, NULL, NULL), huffmanTree);
    }

    //Traverse through tree and put binary values for each char in the table
    char emptyString[MAX_BINARY_LEN];
    emptyString[0]  = '\0';
    insert_binary_values_into_table(huffmanTree, valueTable, emptyString);

    //Create output   file
    FILE* encodeOutput = fopen("encodeOutput.txt", "w");

    //Encode the input message into output.txt using the binaries from table
    encode(valueTable, encodeInput, encodeOutput);

    //Close file pointers
    fclose(encodeInput);
    fclose(encodeOutput);

    //Open decode files
    FILE* decodeInput = fopen("encodeOutput.txt", "r");
    FILE* decodeOutput = fopen("decodeOutput.txt", "w");

    //Decode input
    decode(huffmanTree, decodeInput, decodeOutput);

    //Close decode files
    fclose(decodeInput);
    fclose(decodeOutput);

    //End clock
    clock_t endTime = clock();

    //Calculate elapsed time by finding difference (end - begin) and dividing the difference by CLOCKS_PER_SEC to convert to seconds
    timeSpent += (double)(endTime - beginTime) / CLOCKS_PER_SEC;

    //Print execution time
    printf("Encoding and decoding time was %f seconds", timeSpent);
    printf("\nEND! \n");

    //Free all memory
    exit(0);

    //Return Statement
    return 0;

}

//Adam
tree_node* newNode(char value, int frequency, tree_node *left, tree_node *right)
{
    tree_node* node = malloc(sizeof(tree_node));
    node->value = value;
    node->frequency = frequency;
    node->left = left;
    node->right = right;
    return node;
}

//Adam
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

//Adam
tree_node* node_combine (tree_node *n1, tree_node *n2) {
    return(newNode(NULL, (n1->frequency + n2->frequency), n1, n2));
}

//Adam
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


            if (node_compare(t_node1, t_node2) == -1 ) { // curr has lower freq than the key node; iterate
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
        if(inserted!= 1){ // insert at the end of the list
            prev->next = node;
            node->next = NULL;
            inserted = 1;
        }
    }
    return inserted;
}

//Adam
tree_node* huffman_process(pq* pq_main) { // takes the priority queue as input, outputs the root of the completed Huffman Tree
    tree_node* combined_node;
    pq_node* new_pq_node;

    pq_node* smallest = pq_main->head;
    pq_node* second_smallest = smallest->next;
    while(smallest->next != NULL) {
        pq_main->head = second_smallest->next; //set the new front to the 3rd smallest

        combined_node = node_combine(smallest->ptr, second_smallest->ptr); //create an interior node with combined frequencies

        new_pq_node = newPQNode();
        new_pq_node->next = NULL;
        new_pq_node->ptr = combined_node;

        pq_insert(pq_main, new_pq_node); // put the new pq node pointing at the new interior node into the pq

        smallest = pq_main->head;
        second_smallest = smallest->next;
    }

    return smallest->ptr; // this is the root of the completed Huffman Tree
}

//Shailendra
table* create_table()
{
    //Allocate memory for table
    table* valueTable = (table*) malloc(sizeof(table));

    //Initialize values
    valueTable->count = 0;
    valueTable->head = 0;

    //Return table pointer
    return valueTable;
}

//Shailendra
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

//Riley
void encode(table* t, FILE* input, FILE* output){
    char character;
    table_node* current = t->head;    // Sets current to table head, used for traversal
    while ((character = fgetc(input)) != EOF)    // While loop which traverses the input message character by character
    {
        while(current != NULL && current->value != character)    // While loop which traverses table until the character is found or current is NULL
            current = current->next;
        if(current != NULL){    // If current is not NULL we have the letter in the table and write the binary representation of it to the output file
            fprintf(output, "%s", current->binary);
            //printf("SUCCESS --> Printed '%c' to file!\n", character);
        }
        else{ // If current is NULL we have an error as the letter to encode is not the table, thus we print an error message
            printf("\nERROR --> Unable to find letter in given table: '%c'. Exiting Program.\n", character);
            exit(0);
        }
        current = t->head;
    }
}

//Riley
void decode(tree_node* root, FILE* input, FILE* output){
    char binary_char;
    tree_node* current = root;    // Sets current to root, used for traversal

    while((binary_char = fgetc(input)) != EOF){    // While loop which traverses each binary character in encoded message
        switch(binary_char){    // Switch case for encoded message
            case '1':    // If character is '1' current traverses right down the tree
                current = current->right;
                //printf("TRAVERSE RIGHT: %c\n", binary_char);
                break;
            case '0':    // If character is '0' current traverses left down the tree
                current = current->left;
                //printf("TRAVERSE LEFT: %c\n", binary_char);
                break;
            default:    // If character is neither '1' or '0' we print an error message
                printf("ERROR --> '%c' is a non binary character. Exiting Program.\n", binary_char);
                exit(0);
                break;
        }
        if(current->left == NULL || current->right == NULL){    // After going down tree check if NULL is the new current's left or right child
            fprintf(output, "%c", current->value);    // If left or right is NULL we have found a leaf which contains a letter thus we write it to the file
            current = root;    // Return current to root to continue decoding process
        }
    }
}

//Shailendra
void insert_binary_values_into_table(tree_node* huffman_root, table* t, char* binaryString)
{
    //Check if node is a leaf
    if(huffman_root->left == NULL && huffman_root->right == NULL)
    {
        //Create pointer at head of table
        table_node* current = t->head;

        //Cycle through table searching for matching character with one in tree node
        while(current != NULL)
        {
            if(huffman_root->value == current->value)
            {
                strcpy(current->binary, binaryString);
                current = NULL;
            }

            else
            {
                current = current->next;
            }

        }
    }

    //If node is not a leaf
    else
    {
        //Declare Temporary String for traversal
        char copyBinary[10];
        copyBinary[0] = '\0';

        //Traverse left subtree
        strcpy(copyBinary, binaryString);
        strcat(copyBinary, "0");
        insert_binary_values_into_table(huffman_root->left, t, copyBinary);

        //Traverse right subtree
        strcpy(copyBinary, binaryString);
        strcat(copyBinary, "1");
        insert_binary_values_into_table(huffman_root->right, t, copyBinary);
    }

}

//Adam
pq_node* newPQNode() { //creates a new priority queue node

    pq_node* node = malloc(sizeof(pq_node));
    node->next = NULL;
    node->ptr = NULL;
    return node;
}

//Tatiana
table* convert_to_table(FILE *input) { //needs two * instead of one because
    //table *t = (table*) malloc(sizeof(table)); //create a table
    table *t = create_table();

    //assuming input.txt is already opened
    char ch;

    while ((ch = fgetc(input)) != EOF) { //read each character
        table_node *node = search_for_table_node(ch, t);
        if (node == NULL) { //character not in table
            node = (table_node*) malloc(sizeof(table_node)); //create a node
            node->value = ch;
            //node->binary = NULL;
            node->frequency = 1;
            node->next = t->head; //node's next is current table's head

            t->head = node;     //set new head
            t->count++;

        } else { //character is already in the table
            node->frequency += 1; //increase frequency
        }
    }

    return t;
}

//Tatiana
table_node* search_for_table_node(char character, table *t) {
    table_node *current; //create a node

    current = t->head; //assign node to current
    while ((current != NULL) && (current->value != character)) {
        current = current->next; //update current
    }

    return current;
}

//Adam
pq* new_pq (){ //creates a new priority queue
    pq* pq1 = malloc(sizeof(pq));
    pq1->head = NULL;
    return pq1;
}

//Christine
pq* table_to_queue(table* t) {

  pq *queue = new_pq();                     // Initalizes pq
  table_node *current_t = t->head;      // Sets current to the head of the table_node

  // Goes through the length of the table (table_count)
  for (int i = 0; i < t->count; i++) {

    // Makes a new tree node, using the current table node's (current_t) value / freq
    tree_node *tree = newNode(current_t->value, current_t->frequency, NULL, NULL);
    // Increment current_t
    current_t = current_t->next;
    // Makes a new priority queue node
    pq_node *pqNode = newPQNode();
    // Sets the pq node's tree as the tree node created above
    pqNode->ptr = tree;
    // Yeet it into the distance
    pq_insert(queue, pqNode);
  }

  return queue;
}
