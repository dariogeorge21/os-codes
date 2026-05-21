#include <stdio.h>

int main() {
    int pages[100], frames[10], n, f, i, j;
    int faults = 0, index = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++) {
        found = 0;

        // Check if page already in frame
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // Page fault
        if(found == 0) {
            frames[index] = pages[i];
            index = (index + 1) % f;
            faults++;
        }

        // Display frames
        printf("\nPage %d: ", pages[i]);
        for(j = 0; j < f; j++) {
            if(frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}