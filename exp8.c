#include <stdio.h>

int main()
{
    int n, i, j;
    float totalWT = 0, avgWT;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int pid[n], bt[n], pr[n], wt[n];

    // Step 3: Accept burst time and priority for each process
    for (i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("Enter Burst Time and Priority for Process %d: ", pid[i]);
        scanf("%d%d", &bt[i], &pr[i]);
    }

    // Step 4: Sort the processes by ascending priority
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (pr[i] > pr[j])
            {
                // Swap priority
                int temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                // Swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap process ID
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

    // Step 9: Calculate average waiting time
    for (i = 0; i < n; i++)
    {
        totalWT += wt[i];
    }
    avgWT = totalWT / n;

    // Display results
    printf("\nPID\tPriority\tBurst Time\tWaiting Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", pid[i], pr[i], bt[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", avgWT);

    // Step 10: End
    return 0;
}
