#include <stdio.h>

int main() {
    int n, m;

    // n = number of processes
    // m = number of resources
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[n][m];
    int max[n][m];
    int need[n][m];
    int avail[m];

    // Input Allocation Matrix
    printf("\nEnter Allocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    // Input Max Matrix
    printf("\nEnter Max Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Input Available Resources
    printf("\nEnter Available Resources:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    // Calculate Need Matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int finish[n];
    int safeSeq[n];

    for (int i = 0; i < n; i++) {
        finish[i] = 0;
    }

    int count = 0;

    while (count < n) {
        int found = 0;

        for (int i = 0; i < n; i++) {

            // If process not finished
            if (finish[i] == 0) {

                int possible = 1;

                // Check if resources can be allocated
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        possible = 0;
                        break;
                    }
                }

                // If possible, execute process
                if (possible) {

                    for (int j = 0; j < m; j++) {
                        avail[j] += alloc[i][j];
                    }

                    safeSeq[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        // No process could run
        if (found == 0) {
            printf("\nSystem is NOT in safe state\n");
            return 0;
        }
    }

    // Print Safe Sequence
    printf("\nSystem is in SAFE state.\nSafe sequence:\n");

    for (int i = 0; i < n; i++) {
        printf("P%d", safeSeq[i]);

        if (i != n - 1)
            printf(" -> ");
    }

    printf("\n");

    return 0;
}
