#include <stdio.h>

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n], granttpid[n], granttct[n];
    int completed[n], time = 0, count = 0;

    // Input
    for(int i = 0; i < n; i++) {
        pid[i] = i + 1;
        completed[i] = 0;

        printf("Enter AT and BT for P%d: ", pid[i]);
        scanf("%d %d", &at[i], &bt[i]);
    }

    while(count < n) {
        int min = 9999, index = -1;

        // Find shortest job among arrived
        for(int i = 0; i < n; i++) {
            if(at[i] <= time && completed[i] == 0) {
                if(bt[i] < min) {
                    min = bt[i];
                    index = i;
                }
            }
        }

        if(index != -1) {
            // Execute process
            time += bt[index];
            ct[index] = time;
            granttpid[count] = pid[index];
            granttct[count] = time;

            completed[index] = 1;
            count++;
        } else {
            // CPU idle
            time++;
        }
    }

    // Calculate TAT & WT
    for(int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // Output
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    // Average TAT & WT
    int total_tat = 0, total_wt = 0;
    for(int i = 0; i < n; i++) {
        total_tat += tat[i];
        total_wt += wt[i];
    }
    printf("\nAverage TAT: %.2f\n", (float)total_tat / n);
    printf("Average WT: %.2f\n", (float)total_wt / n);

    //Grantt Chart
    printf("\nGrantt Chart:\n");
    for(int i = 0; i < n; i++) {
        printf("| P%d ", granttpid[i]);
    }
    printf("|\n");
    printf("0    ");
    for(int i = 0; i < n; i++) {
        printf("%d    ", granttct[i]);
    }
    printf("\n");
    return 0;
}
    