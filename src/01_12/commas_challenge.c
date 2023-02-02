#include <stdio.h>

#define N_ORDERS 8
#define N_NUMBERS 10
#define COMMAINT 3

int main()
{
	char digitsRL[N_ORDERS];
	const char charzero = '0';
	int values[10] = {
			123, 1899, 48266, 123456, 9876543,
			10100100, 5, 500000, 99000111, 83};
	int n, rem, n_digits;
	for (int i = 0; i < N_NUMBERS; i++)
	{
		n = values[i];
		n_digits = 0;
		while (n > 0)
		{
			// rem = n % (int)pow(10, (n_digits + 1));
			rem = n % 10;
			digitsRL[n_digits] = charzero + rem;
			n -= rem;
			n /= 10;
			n_digits++;
		};
		for (int j = 0; j < n_digits; j++)
		{
			if (j > 0 & ((n_digits - j) % COMMAINT == 0))
				printf(",");
			printf("%c", digitsRL[n_digits - 1 - j]);
		};
		printf("\n");
	}
	return (0);
}
