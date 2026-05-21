#include<stdio.h>

int main(){
	int n, f;
	int faults = 0, index = 0, found = 0, hit = 0;

	printf("Enter number of pages: ");
	scanf("%d", &n);

	// Enter number of frames
	printf("Enter number of frames: ");
	scanf("%d", &f);

	int pages[n], frames[f], time[f];

	// Input page reference string
	printf("Enter the page reference string: ");
	for (int i = 0; i < n; i++){
		scanf("%d", &pages[i]);
	}

	// Initialize frames
	for (int i = 0; i < f; i++){
		frames[i] = -1;
		time[i] = 0;
	}

	// LRU page replacement algorithm

	int counter = 0;
	for (int i = 0; i < n; i++){
		found = 0;

		// Check if page already in frame
		for (int j = 0; j < f; j++){
			if (frames[j] == pages[i]){
				hit++;
				found = 1;
				time[j] = counter++;
				break;
			}
		}
		if (found == 0){
			int pos = 0;
			for (int j = 1; j < f; j++){
				if (time[j] < time[pos]){
					pos = j;
				}
			}
			frames[pos] = pages[i];
			time[pos] = counter++;
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

	printf("Number of page faults: %d\n", faults);
	printf("Number of page hits: %d\n", hit);
	return 0;
}