#include <stdio.h>

int main()
{
    int n, i;
    float totalWT = 0, avgWT;

    // Step 2: Accept number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int pid[n], bt[n], wt[n];

    // Step 3: Accept burst times
    for (i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("Enter Burst Time for Process %d: ", pid[i]);
        scanf("%d", &bt[i]);
    }

    // Step 4: Initialize waiting time for first process
    wt[0] = 0;

    // Step 5-7: Calculate waiting time for each process
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Step 8: Calculate total and average waiting time
    for (i = 0; i < n; i++)
    {
        totalWT += wt[i];
    }
    avgWT = totalWT / n;

    // Display results
    printf("\nPID\tBurst Time\tWaiting Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\n", pid[i], bt[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", avgWT);

    return 0; // Step 9: End
}
