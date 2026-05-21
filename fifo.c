#include<stdio.h>

int main(){
    int pages[100], frames[10], n, f;
    int faults = 0, index = 0, found = 0, hit = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    // Enter number of frames
    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Input page reference string
    printf("Enter the page reference string: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &pages[i]);
    }

    // Initialize frames
    for (int i = 0; i < f; i++){
        frames[i] = -1;
    }

    // FIFO page replacement algorithm
    for (int i = 0; i < n; i++){
        found = 0;

        // Check if page already in frame
        for (int j = 0; j < f; j++){
            if (frames[j] == pages[i]){
                hit++;
                found = 1;
                break;
            }
        }
        if (found == 0){
            frames[index] = pages[i];
            index = (index++) % f;
            faults++;
        }
        // Display frames
        printf("\nPage %d: ", pages[i]);
        for (int j = 0; j < f; j++){
            if (frames[j] != -1){
                printf("%d ", frames[j]);
            } else{
                printf("- ");
            }
        }
    }
    printf("\nTotal Page Faults: %d", faults);
    printf("\nTotal Page Hits: %d", hit);
    return 0;

}