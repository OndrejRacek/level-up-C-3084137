#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define PSIZE 20
#define NOREPEAT 15
#define NTRIALS 100

int main()
{
	char *playlist[PSIZE] = {
			"Like a Rolling Stone", "Satisfaction", "Imagine",
			"What's Going On", "Respect", "Good Vibrations",
			"Johnny B. Goode", "Hey Jude", "What'd I Say",
			"Smells Like Teen Spirit", "My Generation",
			"Yesterday", "Blowin' in the Wind", "Purple Haze",
			"London Calling", "I Want to Hold Your Hand",
			"Maybellene", "Hound Dog", "Let It Be",
			"A Change Is Gonna Come"};
	int frequency[PSIZE];
	int last15[NOREPEAT];
	int x, r, count, j, k;
	bool repeats;

	/* initialize */
	srand((unsigned)time(NULL));
	for (x = 0; x < PSIZE; x++)
		frequency[x] = 0;
	for (int i = 0; i < NOREPEAT; i++)
		last15[i] = -1;

	/* run through the playlist randomly */
	puts("Playlist:");
	count = 0;
	while (count < NTRIALS)
	{
		repeats = true;
		j = 0;
		do
		{
			/* does r appear in recent[]? */
			r = rand() % PSIZE; /* random value */
			// CHECK IF IN THE LIST OF LAST 15
			k = 0;
			repeats = false;
			while ((k < NOREPEAT) && !repeats)
			{
				if (r == last15[k])
					repeats = true;
				k++;
			}
			j++;
		} while (repeats && (j < 1e3));
		last15[count % NOREPEAT] = r;
		printf("%3d: Now Playing '%s'\n",
					 count + 1,
					 playlist[r]);
		frequency[r]++;
		count++;
	}

	puts("Song frequency:");
	for (x = 0; x < PSIZE; x++)
		printf("%s: %d\n", playlist[x], frequency[x]);

	return (0);
}
