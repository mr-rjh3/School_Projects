#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    // terminates zombie processes
    system("./z_creator &");
    sleep(2);
    printf("-----------------------------------------CURRENT PROCESS LIST-----------------------------------------\n");
    system("ps -l");
    sleep(2);
    
    system("kill -9 $(ps -l|grep -w Z|tr -s ' '|cut -d' ' -f 5)");
    sleep(2);

    printf("\n-----------------------------------------UPDATED PROCESS LIST-----------------------------------------\n");
    system("ps -l");

    return 0;
}