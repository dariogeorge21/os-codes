#include <stdio.h>

int main(void)
{
	int frames, pages;
	if (printf("Enter number of frames: "), fflush(stdout), scanf("%d", &frames) != 1)
		return 0;
	if (printf("Enter number of pages: "), fflush(stdout), scanf("%d", &pages) != 1)
		return 0;

	if (frames <= 0 || pages <= 0)
		return 0;

	if (frames > 10)
		frames = 10;
	if (pages > 50)
		pages = 50;

	int frame[10], ref[50];
	int i, j, k = 0;
	int faults = 0, hits = 0;

	printf("Enter reference string: ");
	for (i = 0; i < pages; i++)
		scanf("%d", &ref[i]);

	for (i = 0; i < frames; i++)
		frame[i] = -1;

	for (i = 0; i < pages; i++) {
		int found = 0;
		for (j = 0; j < frames; j++) {
			if (frame[j] == ref[i]) {
				found = 1;
				hits++;
				break;
			}
		}

		if (!found) {
			frame[k] = ref[i];
			k = (k + 1) % frames;
			faults++;
		}

		/* Print frames */
		printf("\nFrames: ");
		for (j = 0; j < frames; j++) {
			if (frame[j] == -1)
				printf("- ");
			else
				printf("%d ", frame[j]);
		}
	}

	printf("\nPage Faults = %d\n", faults);
	printf("Page Hits = %d\n", hits);

	return 0;
}