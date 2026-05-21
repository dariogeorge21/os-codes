#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int req[100], n, head, total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    sort(req, n);

    printf("Seek Sequence: %d ", head);

int original_head = head;  // save before loops

// Move right first
for(int i = 0; i < n; i++) {
    if(req[i] >= original_head) {
        total += abs(head - req[i]);
        head = req[i];
        printf("-> %d ", head);
    }
}

// Then move left
for(int i = n - 1; i >= 0; i--) {
    if(req[i] < original_head) {   // fixed
        total += abs(head - req[i]);
        head = req[i];
        printf("-> %d ", head);
    }
}
    printf("\nTotal Seek Time = %d\n", total);

    return 0;
}