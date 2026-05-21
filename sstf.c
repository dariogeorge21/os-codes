#include <stdio.h>
#include <stdlib.h>

int main() {
    int requests[100], n, head, totalSeek = 0;
    int visited[100] = {0};

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk request sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: %d ", head);

    for (int i = 0; i < n; i++) {
        int minDist = 9999;
        int index = -1;

        // Find nearest unvisited request
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int dist = abs(head - requests[j]);
                if (dist < minDist) {
                    minDist = dist;
                    index = j;
                }
            }
        }

        visited[index] = 1;
        totalSeek += minDist;
        head = requests[index];

        printf("-> %d ", head);
    }

    printf("\nTotal Seek Time = %d\n", totalSeek);

    return 0;
}