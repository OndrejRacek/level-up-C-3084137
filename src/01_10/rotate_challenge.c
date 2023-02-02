#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 5

char *rotmatrix(char mtrx_in[])
{
  char *mtrx_out = (char *)malloc(N ^ 2 * sizeof(char));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      mtrx_out[i * N + j] = mtrx_in[i + (N - 1 - j) * N];
    }
  }
  return mtrx_out;
}

void printmatrix(char mtrx_in[])
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      printf("%c", mtrx_in[i * N + j]);
      if (j < N - 1)
        printf(", ");
    }
    printf("\n");
  }
}

int main()
{
  char mtrx[N][N];
  char *mtrx_dyn;
  srand((unsigned)time(NULL));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      mtrx[i][j] = 'A' + (char)(rand() % 26);
      // printf("%c", mtrx[i][j]);
      // if (j < N - 1)
      //   printf(", ");
    }
    // printf("\n");
  }
  printf("\n");
  printmatrix(mtrx);
  printf("\n");
  mtrx_dyn = rotmatrix(mtrx);
  printmatrix(mtrx_dyn);
  free(mtrx_dyn);
  // for (int j = N - 1; j >= 0; j--)
  // {
  //   for (int i = 0; i < N; i++)
  //   {
  //     printf("%c", mtrx[i][j]);
  //     if (i < N - 1)
  //       printf(", ");
  //   }
  //   printf("\n");
  // }

  return 0;
}