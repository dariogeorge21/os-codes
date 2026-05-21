#include <stdio.h>

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], pr[n], ct[n], tat[n], wt[n], completed[n], grantpid[n], grantct[n];

    int time = 0, count = 0;

    // Input
    for(int i = 0; i < n; i++) {
        pid[i] = i + 1;
        completed[i] = 0;

        printf("Enter AT, BT and Priority for P%d: ", pid[i]);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
    }

    // Priority Scheduling Logic
    while(count < n) {
        int min = 9999, index = -1;

        for(int i = 0; i < n; i++) {
            if(at[i] <= time && completed[i] == 0) {
                if(pr[i] < min) {   // <-- ONLY CHANGE from SJF
                    min = pr[i];
                    index = i;
                }
            }
        }

        if(index != -1) {
            time += bt[index];
            ct[index] = time;
            grantpid[count] = pid[index];
            grantct[count] = time;

            completed[index] = 1;
            count++;
        } else {
            time++; // CPU idle
        }
    }

    // Calculate TAT and WT
    for(int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // Output
    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++) {
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], pr[i],
               ct[i], tat[i], wt[i]);
    }

    // Calculate and print averages
    int total_tat = 0, total_wt = 0;
    for(int i = 0; i < n; i++) {
        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("\nAverage TAT = %.2f", (float)total_tat / n);
    printf("\nAverage WT = %.2f\n", (float)total_wt / n);

    //grantt chart

    printf("\nGrantt Chart:\n");
    for (int i = 0; i < n; i++){
        printf("| P%d\t", grantpid[i]);
    }
    printf("|\n");
    printf("0");
    for (int i = 0; i < n; i++){
        printf("\t%d", grantct[i]);
    }
    printf("\n");

    return 0;
}