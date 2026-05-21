#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n], completed[n], time = 0, count = 0, grantid[n], grantct[n];
    int total_tat = 0, total_wt = 0;
    
    for (int i = 0; i < n; i++){
        pid[i] = i + 1;
        grantid[i] = pid[i];
        grantct[i] = 0;
        completed[i] = 0;
        printf("Enter the arrival time and the burst time for the process %d: ", pid[i]);
        scanf("%d", &at[i]);
        scanf("%d", &bt[i]);
    } 

    // execution

    while (count < n){
        int index = -1, min = 9999;

        for (int i = 0; i < n; i++){
            if (((at[i]) <= time) && (completed[i] == 0)){
                if (bt[i] < min){
                    min = bt[i];
                    index = i;
                }
            }
        }

        if (index != -1){
            time+=bt[index];
            completed[index] = 1;
            ct[index] = time;
            grantid[count] = pid[index];
            grantct[count] = time;
            count++;
        } else{
            time++;
        }
    }

    for(int i = 0; i < n; i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    for (int i = 0; i < n; i++){
        total_tat += tat[i];
        total_wt += wt[i];
    }

    int avg_total_tat = total_tat/n;
    int avg_total_wt = total_wt/n;

    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0 ; i < n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    } printf("\n");

    // avg

    printf("Average Turnaround Time: %d\n", avg_total_tat);
    printf("Average Waiting Time: %d\n", avg_total_wt);

    // grantt chart
    printf("Grantt Chart:\n");

    for (int i = 0; i < n; i++){
        printf("| P%d\t", grantid[i]);
    } printf("|\n");
    printf("0");
    for (int i = 0; i < n; i++)
    {
        printf("\t%d", grantct[i]);
    }
    printf("\n");
    return 0;
}