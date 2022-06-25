#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>

// Global Variables (Accessible by all threads)
bool valid = true; // Is the sudoku solution valid (Default is True)
int sudokuGrid[10][10]; // 2D array of the sudoku grid

void* rowValid(void* column){ // Give a row index and function will see if that row is valid for sudoku
    int index = *((int*) column) +1; // casts the void pointer of the index to an integer
    for(int i = 1; i < 10; i++){ // loop through all values in the given row
        for(int j = i + 1; j < 10; j++){ // Loop through all values after current index i
            if(sudokuGrid[i][index] == sudokuGrid[j][index]){ // Check if current value has a duplicate
                printf("DUPE: %d | ROW: %d\n", sudokuGrid[i][index+1], index + 1);
                valid = false; // If there is a duplicate the sudoku is not valid 
                return NULL;
            }
        }
    }
    //printf("\n");
    return NULL;   
}

void* columnValid(void* row){ // Give a column index and function will see if that row is valid for sudoku
    int index = *((int*) row) +1; // casts the void pointer of the index to an integer
    for(int i = 1; i < 10; i++){ // loop through all values at the index
        for(int j = i + 1; j < 10; j++){ // Loop through all values after current index i
            if(sudokuGrid[index][i] == sudokuGrid[index][j]){ // Check if current value has a duplicate
                //printf("DUPE: %d | COLUMN: %d\n", sudokuGrid[index+1][i], index + 1);
                valid = false; // If there is a duplicate the sudoku is not valid 
                return NULL;
            }
        }
    }
    //printf("\n");
    return NULL;    
}

void* gridValid(void* grid){ // Give a grid index and this function will see if the grid is valid for sudoku
    int index = *((int*) grid); // casts the void pointer of the index to an integer
    int gridArrayIndex = 0;
    int gridArray[10];
    int offsetX;
    int offsetY;

    // Get the neccesary offset for x and y values from the given index
    if(index < 3){
        offsetX = index * 3;
        offsetY = 0;
    }
    else if(index >= 3 && index < 6){
        offsetX = (index - 3) * 3;
        offsetY = 3;
    }
    else{
        offsetX = (index - 6) * 3;
        offsetY = 6;
    }

    // Insert all values of the 3x3 grid into a 1D array for easier computation 
    for(int i = 1; i < 4; i++){ 
        for(int j = 1; j < 4; j++){
            gridArray[gridArrayIndex] = sudokuGrid[i+offsetX][j+offsetY];
            gridArrayIndex++;
        }
    }   
    //printf("\n");

    for(int i = 0; i < 9; i++){ // loop through all values of the grid
        for(int j = i + 1; j < 9; j++){  // Loop through all values after current index
            if(gridArray[i] == gridArray[j]){ // Check if current value has a duplicate
                //printf("DUPE: %d | GRID: %d\n", gridArray[i], index + 1);
                valid = false; // If there is a duplicate the sudoku is not valid
                return NULL;
            }
        }
    }
    // printf("\n");
    return NULL;
}

int main(int argc, char **argv) {
    
    FILE* sudoku = fopen("sample1_in.txt", "r");
    char string[50];
    

    int row = 0;
    int column = 0;
    // Keep reading the file line by line
    while(fgets(string, 50, sudoku)) {
        //printf("%s", string);
        char* trim_string = strtok(string, " ");
    
        // Split each line of the file into each value
        while (trim_string != NULL) {
            //printf("%s ", trim_string);
            sudokuGrid[row][column] = atoi(trim_string);    
            //printf("%d \n", grade_matrix[row][column]);
            trim_string = strtok(NULL, " ");
            row++;
        }
        row = 0;
        column++;
    }
    // print sudoku grid
    printf("Sudoku input is: \n");
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            printf("%d ", sudokuGrid[j][i]);
        } 
        printf("\n");
    }

    // Create threads
    pthread_t rowThreads[9];
    pthread_t columnThreads[9];
    pthread_t gridThreads[9];

    for(int i = 0; i < 9; i++){ // Loop through all possible indicies to check for validity
        int *index = malloc(sizeof(*index));
        if ( index == NULL ) {
            fprintf(stderr, "Couldn't allocate memory for thread index.\n");
            exit(EXIT_FAILURE);
        }
        *index = i;
        pthread_create(&rowThreads[i], NULL, rowValid, (void*)index); // Check validity of row i using a thread
        pthread_create(&columnThreads[i], NULL, columnValid, (void*)index); // Check validity of column i using a thread
        pthread_create(&gridThreads[i], NULL, gridValid, (void*)index); // Check validity of grid i using a thread
    }

    // Wait for threads to finish
    for(int i = 0; i < 9; i++){
        pthread_join(rowThreads[i], NULL);
        pthread_join(columnThreads[i], NULL);
        pthread_join(gridThreads[i], NULL);
    }

    // State whether the sudoku is valid or not
    if(valid){
        printf("Sudoku is valid\n");
    }
    else{
        printf("Sudoku is invalid\n");
        return 0;
    }

}