#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int X = 10;
    // Makes a zombie process
    pid_t pid;
    pid = fork();
    if(pid < 0){
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if(pid == 0){
        // Child Process
        printf("Z_CREATOR: Zombie Process Created\n");
        exit(1); // Immediately close child process without the parent waiting for it to create a zombie process
    }
    else{
        // Parent Process 
        sleep(X);   // Sleep process to give time to terminate the zombie process
    }

    return 0;
}
