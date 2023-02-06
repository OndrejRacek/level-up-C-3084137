#include <stdio.h>

#define W_MAX 100
#define W_MIN 16
#define W_DEFAULT 40

struct spaces
{
	int txtpos;
	int linepos;
};

void output_line(char *text, int bol, int ccnt)
{
	for (int i = bol; i < bol + ccnt; i++)
	{
		printf("%c", text[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	/* Shakespear's 18th Sonnet */
	static char *text = "Shall I compare thee to a summer's day? \
Thou art more lovely and more temperate:\n\
Rough winds do shake the darling buds of May, \
And summer's lease hath all too short a date;\n\
Sometime too hot the eye of heaven shines, \
And often is his gold complexion dimm'd;\n\
And every fair from fair sometime declines, \
By chance or nature's changing course untrimm'd;\n\
But thy eternal summer shall not fade, \
Nor lose possession of that fair thou ow'st;\n\
Nor shall death brag thou wander'st in his shade, \
When in eternal lines to time thou grow'st:\n\
So long as men can breathe or eyes can see, \
So long lives this, and this gives life to thee.";

	int i, ccnt, bol, lastspc, linewidth;
	i = ccnt = 0;
	lastspc = -1;
	linewidth = W_DEFAULT;
	// printf("Called with %d arguments\n", argc);
	if (argc == 1)
		printf("Default width of %d characters\n", linewidth);
	else if (argc == 2)
	{
		// printf("Enter the line width\n");
		sscanf(argv[1], "%d", &linewidth);
		// printf("Argument value = %d\n", linewidth);
	}
	else
	{
		printf("The function takes only one optional argument\n");
		return 0;
	}

	while (text[i] != '\0')
	{
		// printf("%c", text[i]);
		// whenever the character count ccnt is reset it is a beggining of a line
		if (ccnt == 0)
			bol = i;
		if (text[i] == '\n')
		{
			output_line(text, bol, ccnt);
			ccnt = 0;
			lastspc = -1;
		}
		else
		{
			if (text[i] == ' ' & ccnt == 0)
			{
				bol++;
			}
			else
			{
				ccnt++;
				// lastspc is the index of the last encountered white character
				if (text[i] == ' ')
					lastspc = ccnt;
				if (ccnt % linewidth == 0)
				{
					// printf(" %d\n", ccnt);
					if (lastspc > -1)
					{
						output_line(text, bol, lastspc - 1);
						bol += lastspc; // one character after the space (lastspc is the count of characters upto and including the white space)
						ccnt -= lastspc;
						lastspc = -1;
					}
					else
					{
						output_line(text, bol, ccnt);
						ccnt = 0;
						lastspc = -1;
					}
				}
				else
				{
					if (text[i + 1] == '\0')
						output_line(text, bol, ccnt);
				}
			}
		};
		i++;
	}
	// printf("%s", text);
	return (0);
}
