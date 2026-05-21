#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n], rem_bt[n], grantid[n], grantct[n];
    int count = 0, time = 0;

    for (int i = 0; i < n; i++){
        printf("Enter the AT and BT of process P%d: ", i+1);
        pid[i] = i+1;
        scanf("%d", &at[i]);
        scanf("%d", &bt[i]);
    }

    // initialize remaining burst time
    for (int i = 0; i < n; i++){
        rem_bt[i] = bt[i];
    }

    printf("Enter time quantum: ");
    int time_quantum;
    scanf("%d", &time_quantum);

    // round robin
    while (count < n){
        int executed = 0;

        for (int i = 0; i < n; i++){
            if (at[i] <= time && rem_bt[i]>0){
                executed = 1;
                if (rem_bt[i] > time_quantum){
                    time += time_quantum;
                    rem_bt[i] -= time_quantum;
                } else{
                    time += rem_bt[i];
                    ct[i] = time;
                    grantid[count] = pid[i];
                    grantct[count] = ct[i];
                    rem_bt[i] = 0;
                    count++;
                }
            }
        }

        if (executed == 0){
            // No process was executed, so we just move to the next time unit
            time++;
        }
    }

    // tat and wt
    for (int i = 0; i < n; i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // total tat and wt

    int total_tat = 0, total_wt = 0;
    for (int i = 0; i < n; i++){
        total_tat += tat[i];
        total_wt += wt[i];
    }

    // printing the results
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    // average tat and wt
    printf("Average Turnaround Time: %.2f\n", (float)total_tat/n);
    printf("Average Waiting Time: %.2f\n", (float)total_wt/n); 

    // Grantt chart
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++){
        printf("| P%d ", grantid[i]);
    }
    printf("|\n");
    printf("0 ");
    for (int i = 0; i < n; i++){
        printf("%d ", grantct[i]);
    }
    printf("\n");

    return 0;    
}