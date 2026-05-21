#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n];

    for (int i = 0; i < n; i++){
        printf("Enter the AT and BT of process P%d: ", i+1);
        pid[i] = i+1;
        scanf("%d", &at[i]);
        scanf("%d", &bt[i]);
    }

    // Sorting

    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (at[j] > at[j+1]){
                int temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;

                temp = pid[j];
                pid[j] = pid[j+1];
                pid[j+1] = temp;

                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;
            }
        }
    }

    // ct calculation

    ct[0] = at[0] + bt[0];

    for (int i = 1; i < n; i++){
        if (at[i] > ct[i-1]){
            ct[i] = at[i] + bt[i];
        } else{
            ct[i] = ct[i-1] + bt[i];
        }
    }

    // tat and wt

    for (int i = 0; i < n; i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // total

    int total_tat = 0, total_wt = 0;

    for (int i = 0; i < n; i++){
        total_tat += tat[i];
        total_wt += wt[i];
    }

    // avg

    int avg_tat = total_tat/n;
    int avg_wt = total_wt/n;

    printf ("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\n");
    printf("Average TAT = %d\n", avg_tat);
    printf("Average WT = %d\n", avg_wt);

    // print gantt chart

    printf("Grantt Chart:\n");
    for (int i = 0; i < n; i++){
        printf("| P%d\t", pid[i]);
    }
    printf("|\n");
    printf("0");
    for (int i = 0; i < n; i++){
        printf("\t%d", ct[i]);
    }
    printf("\n");
    return 0;    
}