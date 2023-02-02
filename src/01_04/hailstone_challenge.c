#include <stdio.h>

int main()
{
  int n;
  printf("Enter a starting integer number\n: ");
  scanf("%d", &n);
  if (n > 1)
  {
    printf("%d, ", n);
    while (n > 1 && n < 1000)
    {
      if (!(n % 2))
      {
        n /= 2;
      }
      else
      {
        n = 3 * n + 1;
      }
      printf("%d", n);
      if (n > 1)
      {
        printf(", ");
      }
    }
  }
  else
  {
    printf("The number has to be > 1");
  }
  return 0;
}