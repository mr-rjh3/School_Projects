#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>

bool valid = true;
int sudokuGrid[10][10];

void* columnValid(void* row){
    int index = *((int*) row);
    for(int i = 1; i < 10; i++){ 
        //printf("%d ", sudokuGrid[index+1][i]);
        for(int j = i + 1; j < 10; j++){
            if(sudokuGrid[index+1][i] == sudokuGrid[index+1][j]){
                printf("DUPE: %d | COLUMN: %d\n", sudokuGrid[index+1][i], index + 1);
                valid = false;
                return NULL;
            }
        }
    }
    //printf("\n");
    return NULL;    
}

void* rowValid(void* column){
    int index = *((int*) column);
    for(int i = 1; i < 10; i++){ 
        //printf("%d ", sudokuGrid[i][index+1]);
        for(int j = i + 1; j < 10; j++){
            if(sudokuGrid[i][index+1] == sudokuGrid[j][index+1]){
                printf("DUPE: %d | ROW: %d\n", sudokuGrid[i][index+1], index + 1);
                valid = false;
                return NULL;
            }
        }
    }
    //printf("\n");
    return NULL;   
}

void* gridValid(void* grid){
    int index = *((int*) grid);
    int gridIndex = 0;
    int gridArray[10];
    int offsetX;
    int offsetY;
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
    //printf("%d %d\n", offsetX, offsetY);
    for(int i = 1; i < 4; i++){ 
        for(int j = 1; j < 4; j++){
            gridArray[gridIndex] = sudokuGrid[i+offsetX][j+offsetY];
            //printf("%d ", gridArray[gridIndex]);
            gridIndex++;
        }
    }   
    //printf("\n");

    for(int i = 0; i < 9; i++){ 
        // printf("%d ", gridArray[i]);
        for(int j = i + 1; j < 9; j++){
            if(gridArray[i] == gridArray[j]){
                printf("DUPE: %d | GRID: %d\n", gridArray[i], index + 1);
                valid = false;
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
    
        // Split each line of the file into each individual grade
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

    for(int i = 0; i < 9; i++){
        int *index = malloc(sizeof(*index));
        if ( index == NULL ) {
            fprintf(stderr, "Couldn't allocate memory for thread index.\n");
            exit(EXIT_FAILURE);
        }
        *index = i;
        pthread_create(&rowThreads[i], NULL, rowValid, (void*)index);
        pthread_create(&columnThreads[i], NULL, columnValid, (void*)index);
        pthread_create(&gridThreads[i], NULL, gridValid, (void*)index);
    }

    // Wait for threads to finish
    for(int i = 0; i < 9; i++){
        pthread_join(rowThreads[i], NULL);
        pthread_join(columnThreads[i], NULL);
        pthread_join(gridThreads[i], NULL);
    }

    if(valid){
        printf("Sudoku is valid\n");
    }
    else{
        printf("Sudoku is invalid\n");
        return 0;
    }

}