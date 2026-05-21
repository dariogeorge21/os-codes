#include<stdio.h>

int main(){
    int r, c;
    printf("Enter the number of processes: ");
    scanf("%d", &r);
    printf("Enter the number of resources: ");
    scanf("%d", &c);

    int alloc[r][c], max[r][c], need[r][c];
    int work[c], avail[c];
    int finish[r], safe[r];

    for (int i = 0; i < r; i++){
        printf("Enter the allocation for process P%d: ", i+1);
        for (int j = 0; j < c; j++){
            scanf("%d", &alloc[i][j]);
        }
    }

    for (int i = 0; i < r; i++){
        printf("Enter the maximum demand for process P%d: ", i+1);
        for (int j = 0; j < c; j++){
            scanf("%d", &max[i][j]);
        }
    }

    for (int i = 0; i < c; i++){
        printf("Enter the available amount of resource R%d: ", i+1);
        scanf("%d", &avail[i]);
        work[i] = avail[i];
    }

    // Calculate need matrix
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // iniitialize finish array
    for (int i = 0; i < r; i++){
        finish[i] = 0;
    }

    int count = 0;

    while (count < r){
        int found = 0;

        for (int i = 0; i < r; i++){
            if (finish[i] == 0){
                int flag = 0;
                for (int j = 0; j < c; j++){
                    if (need[i][j] > work[j]){
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0){
                    for (int j = 0; j < c; j++){
                        work[j] += alloc[i][j];
                    }
                    finish[i] = 1;
                    safe[count] = i;
                    count++;
                    found = 1;
                }
            }
        }
        if (found == 0){
            printf("System is in unsafe state!\n");
            break;
        }
    }
    printf("Safe sequence is: ");
    for (int i = 0; i < count; i++){
        printf("P%d ", safe[i]+1);
    }
    printf("\n");
    return 0;
}

