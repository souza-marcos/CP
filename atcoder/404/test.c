#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int value = 5;

int main(){
    pid_t pid;


    pid = fork();
    fork();
    if(pid < 0) {
        printf("Fork failed\n");
        return 1;
    } else if(pid == 0) {
        // Child process
        printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        // execlp("/bin/ps", "ps -el", NULL);
        value += 5;
        printf("Child process value: %d\n", value);
        exit(0);
        printf("This line will not be executed because execlp replaces the process image\n");
    } else {
        // Parent process
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
        int status;
        wait(&status); // Wait for child process to finish
        printf("Child process finished with status %d\n", status);
        printf("Parent process value: %d\n", value);
    }
    printf("End of process: PID = %d\n", getpid());
    return 0;
}   