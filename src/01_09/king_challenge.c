#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define INITCOL 5
#define INITROW 4
#define MAXCOL 8
#define MAXROW 8
#define MAXNMOVES 100

struct loc
{
  int i;
  int j;
};

// void print_king(int rows[], int cols[])
void print_king(struct loc pstns[])
{
  int i;
  char chars1[MAXROW * MAXCOL];
  for (i = 0; i < MAXROW; i++)
  {
    for (int j = 0; j < MAXCOL; j++)
    {
      chars1[i * MAXCOL + j] = '.';
    }
  }
  i = 0;
  while ((pstns[i].i - 1 > -1) && (pstns[i].j - 1 > -1) && i < MAXNMOVES)
  {
    chars1[(pstns[i].i - 1) * MAXCOL + pstns[i].j - 1] = 'O';
    i++;
  }

  for (int i = 0; i < MAXROW; i++)
  {
    for (int j = 0; j < MAXCOL; j++)
    {
      printf(" %c ", chars1[i * MAXCOL + j]);
    }
    printf("\n");
  }
}

struct loc ij2loc(int i, int j)
{
  struct loc loc1;
  loc1.i = i;
  loc1.j = j;
  return loc1;
}

int main()
{
  int i, j, N_moves;
  struct loc pstns[MAXNMOVES];

  srand((unsigned)time(NULL));
  /*INITIALIZE THE "PATH"*/
  pstns[0] = ij2loc(INITROW, INITCOL);
  for (i = 1; i < MAXNMOVES; i++)
  {
    pstns[i] = ij2loc(-1, -1);
  }

  printf("Initial position:\n");
  print_king(pstns);
  i = INITROW;
  j = INITCOL;
  N_moves = 0;
  while (i >= 0 && i < MAXROW && j >= 0 && j < MAXCOL && N_moves < MAXNMOVES)
  {
    i += rand() % 3 - 1;
    j += rand() % 3 - 1;
    N_moves++;
    pstns[N_moves] = ij2loc(i, j);
  }
  printf("Final position after %d moves:\n", N_moves);
  print_king(pstns);
  return 0;
}