#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>

void writeOutput(char* command, char* output)
{
        /* Complete code to save the commands in a output.txt*/
    FILE *fp;
    fp = fopen("output.txt", "a");
	fprintf(fp, "The output of: %s : is\n", command);
	fprintf(fp, ">>>>>>>>>>>>>>>\n%s<<<<<<<<<<<<<<<\n", output);	
    fclose(fp);
}

int main(int argc, char *argv[]) {

    // CONSTANTS
    const int SIZE = 4096; // Size of shared memory object
    const char *name = "shared_memory"; // Name of shared memory object
    const int READ = 0; // Read file descriptor
    const int WRITE = 1; // Write file descriptor
    const char* IN_FILE_NAME = "sample_in_process.txt"; // Name of file to be read

    int shm_fd; // Shared memory file descriptor
    char *shm_base;	// base address, from mmap()

    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666); // Created shared memory object
    if (shm_fd == -1) {
        printf("Shared memory failed: %s\n", strerror(errno));
        exit(1);
    }

    ftruncate(shm_fd, SIZE); // Configure size of shared memory object

    shm_base = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0); // Memory map the shared memory object
    if (shm_base == MAP_FAILED) {
        printf("Map failed: %s\n", strerror(errno));
        exit(1);
    }

    void *ptr = shm_base; // Pointer to shared memory object

    // Fork a child process
    pid_t pid;
    pid = fork();
    if(pid < 0){
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if(pid == 0){
        // Child process that reads commands from file
        FILE *fp;
        char command[255];
        fp = fopen(IN_FILE_NAME, "r");
        while(fgets(command, 255, fp)){ // Reads commands from file
            ptr += sprintf(ptr, "%s", command); // Writes commands to shared memory object
        }
        fclose(fp);
        exit(0);
        
    }
    else{
        // Parent Process 
        wait(NULL); // Wait for child to finish
        char *commands = (char *)shm_base; // Get pointer to shared memory object

        // Create pipes
        int pipe1[2];
        int pipe2[2];
        if(pipe(pipe1) == -1){ // Create pipe 1
            fprintf(stderr, "Pipe failed\n");
            exit(1);
        }
        if(pipe(pipe2) == -1){ // Create pipe 2
            fprintf(stderr, "Pipe failed\n");
            exit(1);
        }

        // Fork again
        pid_t pid2;
        pid2 = fork();
        if(pid < 0){
            fprintf(stderr, "Fork failed\n");
            exit(1);
        }
        else if(pid2 == 0){
            // Child that executes commands from file
            FILE *fp;
            char *token = strtok(commands, "\n"); // Tokenize commands
            char *output = malloc(SIZE); // Allocate memory for output
            size_t length;
            ssize_t bytes_read;

            // Close read end of pipes
            close(pipe1[READ]);
            close(pipe2[READ]);

            // Execute commands
            while(token != NULL){
                fp = popen(token, "r"); // Execute command and store output in file
                bytes_read = getdelim( &output, &length, '\0', fp); // Read output from file
                pclose(fp); // Close file
                if (bytes_read != -1) { // If output is not empty
                    write(pipe1[WRITE], output, SIZE); // Write output to pipe 1
                    write(pipe2[WRITE], token, SIZE);  // Write command to pipe 2
                }
                token = strtok(NULL, "\n"); // Next command
            }

            // Close write end of pipes
            close(pipe1[WRITE]);
            close(pipe2[WRITE]);
            exit(0);
        }
        else{
            // Parent Process

            char *output = malloc(SIZE); // Allocate memory for output
            char *token = malloc(SIZE); // Allocate memory for command

            // Close write end of pipes
            close(pipe1[WRITE]);
            close(pipe2[WRITE]);

            // Read from pipes
            while(read(pipe1[READ], output, SIZE) > 0){
                read(pipe2[READ], token, SIZE);
                writeOutput(token, output); // Write output to file
            }

            // Close read end of pipes
            close(pipe1[READ]);
            close(pipe2[READ]);

            wait(NULL); // Wait for child to finish
            
            if (munmap(ptr, SIZE) == -1) { // Unmap shared memory object
            printf("Unmap failed: %s\n", strerror(errno));
            exit(1);
            }
            if (close(shm_fd) == -1) { // Close shared memory file descriptor
                printf("Close failed: %s\n", strerror(errno));
                exit(1);
            }
            if (shm_unlink(name) == -1) { // Unlink shared memory object
                printf("Error removing %s: %s\n", name, strerror(errno));
                exit(1);
            }

            exit(0);
        }
    }
}
