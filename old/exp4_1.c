// Example: fork() with Process IDs

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid, mypid, myppid;
    
    pid = getpid();
    printf("Before fork: Process ID is %d\n", pid);
    
    pid = fork();
    if (pid < 0) {
        perror("fork() failure\n");
        return 1;
    }
    
    if (pid == 0) { // Child process
        printf("This is child process\n");
        mypid = getpid();
        myppid = getppid();
        printf("Process ID: %d, Parent ID: %d\n", mypid, myppid);
    } else { // Parent process
        sleep(2);
        printf("This is parent process\n");
        mypid = getpid();
        myppid = getppid();
        printf("Process ID: %d, Parent ID: %d\n", mypid, myppid);
        printf("Newly created child process ID: %d\n", pid);
    }
    return 0;
}