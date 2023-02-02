#include <stdio.h>
#include <stdlib.h>

char *left(char *s, int len)
{
	char *lstr;
	lstr = malloc(len * sizeof(char) + 1);
	for (int i = 0; i < len; i++)
	{
		lstr[i] = s[i];
	}
	lstr[len] = '\0';
	return lstr;
}

char *right(char *s, int len)
{
	char *rstr, *s_end;
	rstr = malloc(len * sizeof(char) + 1);
	s_end = s;
	while (*s_end != '\0')
		s_end++;
	for (int i = 0; i < len; i++)
	{
		rstr[len - i - 1] = s_end[-i];
	}
	rstr[len] = '\0';
	return rstr;
}

char *mid(char *s, int offset, int len)
{
	char *mstr;
	mstr = malloc(len * sizeof(char) + 1);

	for (int i = 0; i < len; i++)
	{
		mstr[i] = s[offset + i];
	}
	mstr[len] = '\0';
	return mstr;
}

int main()
{
	char *str1, *str2, *str3;
	char string[] = "Once upon a time, there was a string";

	str1 = left(string, 16);
	str2 = right(string, 18);
	str3 = mid(string, 13, 12);

	printf("Original string: %s\n", string);
	printf("Left %d characters: %s\n", 16, str1);
	printf("Right %d characters: %s\n", 18, str2);
	printf("Middle %d characters: %s\n", 11, str3);

	free(str1);
	free(str2);
	free(str3);

	return (0);
}
