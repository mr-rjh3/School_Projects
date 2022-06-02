#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    
    FILE* grades = fopen("sample_in_grades.txt", "r");
    //6 rows, 10 columns
    int grade_matrix[6][10];
    //int line[6];
    char string[50];
    int row = 0;
    int column = 0;

    // Keep reading the file line by line
    while(fgets(string, 50, grades)) {
        //printf("%s", string);
        char* trim_string = strtok(string, " ");
    
        // Split each line of the file into each individual grade
        while (trim_string != NULL) {
            //printf("%s ", trim_string);
            grade_matrix[row][column] = atoi(trim_string);    
            //printf("%d \n", grade_matrix[row][column]);
            trim_string = strtok(NULL, " ");
            row++;
        }

        row = 0;
        column++;
    }

    // for (int i = 0; i < 6; i++) {
    //     for (int j = 0; j < 10; j++) {
    //         printf("%d ", grade_matrix[i][j]);
    //     } 
        
    //     printf("\n");
    // }
    // printf("\n");

    fclose(grades);

    // Fork 3 GTA processes
    for(int count = 0; count < 3; count++){ 
            pid_t GTA;
            GTA = fork();
            if(GTA < 0){
                printf("Fork Failed");
                exit(1);
            }
            else if (GTA == 0) {
                // GTA process:  Splits grades into 3 chapters and gives them to 2 TA processes

                if(count == 0){
                    // GTA 1 --> Split chapter 1 into assignment 1, 2
                    int assignment_1[10];
                    int assignment_2[10];
                    for (int i = 0; i < 2; i++) {
                        for (int j = 0; j < 10; j++) {
                            if(i == 0){
                                assignment_1[j] = grade_matrix[i][j]; // Assignment 1
                            }
                            else{
                                assignment_2[j] = grade_matrix[i][j]; // Assignment 2
                            }
                        }
                    }
                    // Fork 2 TA processes
                    for(int TA = 0; TA < 2; TA++){
                        pid_t TA_PID;
                        TA_PID = fork();
                        if(TA_PID < 0){
                            printf("fork failed");
                            exit(1);
                        }
                        else if(TA_PID == 0){
                            // TA process: Gets the average for assignments 
                            if(TA == 0){
                                // TA 1 --> Assignment 1
                                float sum = 0;
                                for (int i = 0; i < 10; i++) {
                                    sum += assignment_1[i];
                                }
                                float average = sum/10;
                                printf("ASSIGNMENT 1 AVERAGE: %f\n", average);
                                
                            }
                            else if(TA == 1){
                                // TA 2 --> Assignment 2
                                float sum = 0;
                                for (int i = 0; i < 10; i++) {
                                    sum += assignment_2[i];
                                }
                                float average = sum/10;
                                printf("ASSIGNMENT 2 AVERAGE: %f\n", average);
                            }
                            exit(0); // TA process exits
                        }
                    }
                    // GTA 1 Continues
                    for (int i = 0; i < 2; i++) // Wait for TA processes to finish
                        wait(NULL);
                }

                else if(count == 1){
                    // GTA 2 --> Splits Chapter 2 into assignment 3, 4
                    int assignment_3[10];
                    int assignment_4[10];
                    for (int i = 0; i < 2; i++) {
                        for (int j = 0; j < 10; j++) {
                            if(i == 0){
                                assignment_3[j] = grade_matrix[i+2][j]; // Assignment 3
                            }
                            else{
                                assignment_4[j] = grade_matrix[i+2][j]; // Assignment 4
                            }
                        }
                    }
                    // Fork 2 TA processes
                    for(int TA = 0; TA < 2; TA++){
                        // TA process: Gets the average for assignments 
                        pid_t TA_PID;
                        TA_PID = fork();
                        if(TA_PID < 0){
                            printf("fork failed");
                            exit(1);
                        }
                        else if(TA_PID == 0){
                            if(TA == 0){
                                // TA 3 --> Assignment 3
                                float sum = 0;
                                for (int i = 0; i < 10; i++) {
                                    sum += assignment_3[i];
                                }
                                float average = sum/10;
                                printf("ASSIGNMENT 3 AVERAGE: %f\n", average);
                                
                            }
                            else if(TA == 1){
                                // TA 4 --> Assignment 4
                                float sum = 0;
                                for (int i = 0; i < 10; i++) {
                                    sum += assignment_4[i];
                                }
                                float average = sum/10;
                                printf("ASSIGNMENT 4 AVERAGE: %f\n", average);
                            }
                            exit(0);
                        }
                    }
                    // GTA 2 Continues
                    for (int i = 0; i < 2; i++) // Wait for TA processes to finish
                        wait(NULL);
                }
                else if(count == 2){
                    // GTA 3 --> Splits Chapter 3 into assignment 5, 6
                    int assignment_5[10];
                    int assignment_6[10];

                    for (int i = 0; i < 2; i++) {
                        for (int j = 0; j < 10; j++) {
                            if(i == 0){
                                assignment_5[j] = grade_matrix[i+4][j]; // Assignment 5
                            }
                            else{
                                assignment_6[j] = grade_matrix[i+4][j]; // Assignment 6
                            }
                        }
                    }
                    // Fork 2 TA processes
                    for(int TA = 0; TA < 2; TA++){
                        // TA process: Gets the average for assignments 
                        pid_t TA_PID;
                        TA_PID = fork();
                        if(TA_PID < 0){
                            printf("fork failed");
                            exit(1);
                        }
                        else if(TA_PID == 0){
                            if(TA == 0){
                                // TA 5 --> Assignment 5
                                float sum = 0;
                                for (int i = 0; i < 10; i++) {
                                    sum += assignment_5[i];
                                }
                                float average = sum/10;
                                printf("ASSIGNMENT 5 AVERAGE: %f\n", average);
                                
                            }
                            else if(TA == 1){
                                // TA 6 --> Assignment 6
                                float sum = 0;
                                for (int i = 0; i < 10; i++) {
                                    sum += assignment_6[i];
                                }
                                float average = sum/10;
                                printf("ASSIGNMENT 6 AVERAGE: %f\n", average);
                            }
                            exit(0);
                        }
                    }
                    // GTA 3 Continues
                    for (int i = 0; i < 2; i++) // Wait for TA processes to finish
                        wait(NULL);
                }
                exit(0); // GTA process exits
            }
        }
        // Parent Continues
        for(int count = 0; count < 3; count++) // wait for all GTA's to finish
            wait(NULL);

} // END OF MAIN