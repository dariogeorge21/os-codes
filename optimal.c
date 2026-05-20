#include <stdio.h>

int main(void)
{
	int frames, pages;
	if (scanf("%d %d", &frames, &pages) != 2)
		return 0;

	if (frames <= 0 || pages <= 0)
		return 0;

	int frame[10];
	int ref[50];
	int i, j, k, pos;
	int faults = 0;
	int hits = 0;

	for (i = 0; i < pages && i < 50; i++)
		scanf("%d", &ref[i]);

	for (i = 0; i < frames && i < 10; i++)
		frame[i] = -1;

	for (i = 0; i < pages && i < 50; i++) {
		int found = 0;

		/* Check for hit */
		for (j = 0; j < frames && j < 10; j++) {
			if (frame[j] == ref[i]) {
				found = 1;
				hits++;
				break;
			}
		}

		/* On fault, choose optimal victim */
		if (!found) {
			int max = -1;
			pos = -1;

			for (j = 0; j < frames && j < 10; j++) {
				int next = -1;
				for (k = i + 1; k < pages && k < 50; k++) {
					if (frame[j] == ref[k]) {
						next = k;
						break;
					}
				}

				/* If this frame is not used again, replace it immediately */
				if (next == -1) {
					pos = j;
					break;
				}

				/* Otherwise pick the one with farthest next use */
				if (next > max) {
					max = next;
					pos = j;
				}
			}

			if (pos == -1)
				pos = 0;

			frame[pos] = ref[i];
			faults++;
		}
	}

	printf("Page Faults = %d\n", faults);
	printf("Page Hits = %d\n", hits);

	return 0;
}