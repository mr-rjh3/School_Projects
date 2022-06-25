#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void* customThread(){
    printf("%s\n", "Custom Thread Created!!");
    for(int i = 0; i < 5; i++){
        printf("I am the custom thread and I am printing\n");
        sleep(1);
    }
    return NULL;
}

int main(int argc, char **argv) {
    // Create thread
    pthread_t thread_1;
    int iret;
    iret = pthread_create(&thread_1, NULL, customThread, NULL); // Create thread and pass in function to run
    if (iret) { // Error checking
        fprintf(stderr, "Error - pthread_create() return code: %d\n", iret);
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < 5; i++){ 
        printf("I am the main thread and I am printing\n");
        sleep(1);
    }
    // Join thread to main thread
    pthread_join(thread_1, NULL);
    printf("Thread 1 returns: %d\n", iret);


}

// There is some ambiguity in the output. Sometimes the main thread prints multiple times in a row and sometimes the custom does so as well. Other times they are both printed one at a time.

