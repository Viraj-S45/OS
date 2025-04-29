#include <stdio.h>

int main()
{
    int n, i, j;
    float totalWT = 0, avgWT;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int pid[n], bt[n], wt[n];

    // Step 3: Accept burst time for each process
    for (i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("Enter Burst Time for Process %d: ", pid[i]);
        scanf("%d", &bt[i]);
    }

    // Step 4: Sort the processes by ascending burst time
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (bt[i] > bt[j])
            {
                // Swap burst time
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap process ID (to maintain proper PID)
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // Step 5: Initialize WT[0] = 0
    wt[0] = 0;

    // Step 6-8: Calculate waiting time for each process
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Step 9: Calculate total and average waiting time
    for (i = 0; i < n; i++)
    {
        totalWT += wt[i];
    }
    avgWT = totalWT / n;

    // Display the results
    printf("\nPID\tBurst Time\tWaiting Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\n", pid[i], bt[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", avgWT);

    return 0; // Step 10: End
}
