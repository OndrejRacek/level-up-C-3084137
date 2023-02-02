#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define DECKSIZE 26
#define N_CHR_HALF DECKSIZE / 2

bool ChrOrdered(char str1[])
{
  int N_chr = strlen(str1), i = 0;
  bool chr_incr;
  // printf("%d elements:\n", strlen(str1));
  // printf("%s", str1);
  if (N_chr > 1)
  {
    do
    {
      i++;
      chr_incr = (str1[i] > str1[i - 1]);
    } while (i < N_chr && chr_incr);
    if (i == N_chr)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    return true;
  }
}

int main()
{
  char ABC[DECKSIZE];
  char ABC_shffld[DECKSIZE];
  int N_chr = sizeof(ABC) / sizeof(ABC)[0];
  // int N_chr_half = N_chr / 2;
  ABC[0] = 'A';
  for (int i = 1; i < N_chr; i++)
  {
    ABC[i] = ABC[0] + i;
  }
  printf("ABC has %d letters:\n", N_chr);
  printf(" 0: %s\n", ABC);

  int i = 0;
  do
  {
    for (int j = 0; j < N_chr; j++)
    {
      ABC_shffld[j] = ABC[(j % 2) * N_CHR_HALF + j / 2];
    }
    strcpy(ABC, ABC_shffld);
    printf("%2d: %s\n", i + 1, ABC);
    i++;
  } while (!(ChrOrdered(ABC_shffld)) && i < 100);

  // printf("%d\n", ChrOrdered(ABC));
  printf("Shuffled in %d passes", i);
  return 0;
}