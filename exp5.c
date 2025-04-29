#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid, mypid, myppid;

    // Get PID before fork
    pid = getpid();
    printf("Before fork: Process ID is %d\n", pid);

    // Create child process
    pid = fork();

    // Error handling
    if (pid < 0)
    {
        perror("fork() failure");
        return 1;
    }

    // Child process block
    if (pid == 0)
    {
        printf("\nThis is the child process.\n");
        mypid = getpid();
        myppid = getppid();
        printf("Child Process ID: %d\n", mypid);
        printf("Child's Parent Process ID (PPID): %d\n", myppid);
    }

    // Parent process block
    else
    {
        sleep(2); // Give child time to print first
        printf("\nThis is the parent process.\n");
        mypid = getpid();
        myppid = getppid();
        printf("Parent Process ID: %d\n", mypid);
        printf("Parent's Parent Process ID (PPID): %d\n", myppid);
        printf("Child Process ID (returned by fork): %d\n", pid);
    }

    return 0;
}
