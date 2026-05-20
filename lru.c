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

	int frame[10], ref[50], time[10];
	int i, j, least;
	int faults = 0, hits = 0;
	int counter = 0;

	printf("Enter reference string: ");
	for (i = 0; i < pages; i++)
		scanf("%d", &ref[i]);

	/* Initialize frames and time stamps */
	for (i = 0; i < frames; i++) {
		frame[i] = -1;
		time[i] = 0;
	}

	for (i = 0; i < pages; i++) {
		int found = 0;

		/* Check for hit */
		for (j = 0; j < frames; j++) {
			if (frame[j] == ref[i]) {
				counter++;
				time[j] = counter;
				hits++;
				found = 1;
				break;
			}
		}

		if (!found) {
			/* Try to fill empty frame first */
			for (j = 0; j < frames; j++) {
				if (frame[j] == -1) {
					frame[j] = ref[i];
					counter++;
					time[j] = counter;
					faults++;
					found = 1;
					break;
				}
			}

			/* If no empty frame, replace least recently used */
			if (!found) {
				least = 0;
				for (j = 1; j < frames; j++) {
					if (time[j] < time[least])
						least = j;
				}

				frame[least] = ref[i];
				counter++;
				time[least] = counter;
				faults++;
			}
		}
	}

	printf("Page Faults = %d\n", faults);
	printf("Page Hits = %d\n", hits);

	return 0;
}