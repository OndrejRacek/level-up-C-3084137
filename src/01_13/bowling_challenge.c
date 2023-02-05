#include <stdio.h>
#include <stdbool.h>

#define NROUNDS 10
#define NPINS 10

struct Frame
{
  int throw1;
  int throw2;
  int pts;
};

void print_frames(char *pname, struct Frame scores[], int tot_score)
{
  // int i = 0;
  printf("%-10s:", pname);
  for (int i = 0; i < NROUNDS; i++)
  {
    printf(" ");
    if (scores[i].throw1 >= 0)
    {
      if (scores[i].throw1 > NPINS - 1)
      {
        printf("X");
      }
      else
      {
        printf("%d", scores[i].throw1);
      }
    }
    else
    {
      printf(" ");
    }
    printf("|");
    if (i < NROUNDS - 1)
    {
      if (scores[i].throw2 >= 0 & scores[i].throw1 < NPINS)
      {
        if (scores[i].throw2 + scores[i].throw1 > NPINS - 1)
        {
          printf("/");
        }
        else
        {
          printf("%d", scores[i].throw2);
        }
      }
      else
      {
        printf(" ");
      }
      printf("  ||");
    }
    else
    {
      if (scores[i].throw1 > NPINS - 1)
      {
        if (scores[i + 1].throw1 < NPINS)
          printf("%d|", scores[i + 1].throw1);
        else
          printf("X|");
        if (scores[i + 1].throw2 < NPINS)
          printf("%d", scores[i + 1].throw2);
        else
          printf("X");
      }
      else
      {
        if (scores[i].throw2 >= 0)
        {
          if (scores[i].throw2 + scores[i].throw1 < NPINS)
          {
            printf("%d", scores[i].throw2);
          }
          else
          {
            printf("/");
          }
        }
        printf("  ");
      }
      printf("\n");
    }
  }
  printf("%11s", " ");
  for (int i = 0; i < NROUNDS; i++)
  {
    printf("%6d", scores[i].pts);
    if (i < NROUNDS - 1)
      printf("||");
    else
      printf(" TOTAL: %d pts\n", tot_score);
  }
}

int calc_pts(struct Frame scores[])
{
  int i = 0;
  bool scrclsd = true;
  while ((i < NROUNDS) & scrclsd)
  {
    if (scores[i].throw1 > NPINS - 1)
    {
      if (scores[i + 1].throw1 < NPINS | i >= NROUNDS - 1)
      {
        if ((scores[i + 1].throw1 >= 0) & (scores[i + 1].throw2 >= 0))
        {
          scores[i].pts = NPINS + scores[i + 1].throw1 + scores[i + 1].throw2;
        }
        else
        {
          scores[i].pts = -1;
          scrclsd = false;
        }
      }
      else
      {
        if (scores[i + 2].throw1 >= 0)
        {
          scores[i].pts = 2 * NPINS + scores[i + 2].throw1;
        }
      }
    }
    else
    {
      if ((scores[i].throw1 >= 0) & (scores[i].throw2 >= 0))
      {
        if (scores[i].throw1 + scores[i].throw2 > NPINS - 1 & i < NROUNDS - 1)
        {
          if (scores[i + 1].throw1 >= 0)
          {
            scores[i].pts = NPINS + scores[i + 1].throw1;
          }
          else
          {
            scores[i].pts = -1;
            scrclsd = false;
          }
        }
        else
        {
          scores[i].pts = scores[i].throw1 + scores[i].throw2;
        }
      }
      else
      {
        scores[i].pts = -1;
        scrclsd = false;
      }
    }
    i++;
  };
  int tot_score = -1;
  if (i == NROUNDS & scrclsd)
  {
    tot_score = 0;
    for (int j = 0; j < NROUNDS; j++)
    {
      tot_score += scores[j].pts;
    }
  }
  return tot_score;
}

int main()
{
  // struct Frame P1frames[NROUNDS], P2frames[NROUNDS];
  struct Frame P1frames[NROUNDS + 1] = {{10, 0, -1}, {10, 0, -1}, {10, 0, -1}, {10, 0, -1}, {10, 0, -1}, {10, 0, -1}, {10, 0, -1}, {10, 0, -1}, {10, 0, -1}, {10, 0, -1}, {10, 10, -1}};
  struct Frame P2frames[NROUNDS + 1] = {{8, 2, -1}, {7, 1, -1}, {5, 3, -1}, {2, 10, -1}, {10, 0, -1}, {10, 2, -1}, {10, 1, -1}, {10, 0, -1}, {8, 2, -1}, {9, 1, -1}, {1, 3, -1}};
  int tot_score;

  // for (int i = 0; i < NROUNDS; i++)
  // {
  //   P1frames[i].throw1 = P1frames[i].throw2 = -1;
  //   // P2frames[i] = P1frames[i];
  // }
  tot_score = calc_pts(P1frames);
  print_frames("Nina", P1frames, tot_score);
  printf("\n");
  tot_score = calc_pts(P2frames);
  print_frames("Martin", P2frames, tot_score);
  return 0;
}