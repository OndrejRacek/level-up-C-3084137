#include <stdio.h>
#include <math.h>
int main()
{
  double coinage[] = {0.25, 0.1, 0.05, 0.01};
  double amounts[] = {0.49, 1.27, 0.75, 1.31, 0.83};

  int N_cng = sizeof(coinage) / sizeof(coinage[0]);
  int N_amts = sizeof(amounts) / sizeof(amounts[0]);
  double rmdr;  // holds the remainder of the mount (in cents) while subtracting amounts in coins
  int n_coins;  // number of given coins
  int indx_cng; // index into the set of coins

  printf("Change for %d amounts in %d types of coins\n", N_amts, N_cng);

  for (int i = 0; i < N_amts; i++)
  {
    printf("Amount #%d: %f = ", i, amounts[i]);
    rmdr = amounts[i];
    indx_cng = 0;
    while ((indx_cng < N_cng) & (rmdr > 0))
    {
      n_coins = (int)(round(1e2 * rmdr)) / (int)(round(1e2 * coinage[indx_cng]));
      rmdr = 1e-2 * (float)((int)(round(1e2 * rmdr)) % (int)(round(1e2 * coinage[indx_cng])));
      if (n_coins > 0)
      {
        printf("%d x $%.2f", n_coins, coinage[indx_cng]);
        if (rmdr > 0)
          printf(" + ");
      }
      indx_cng++;
    }
    printf("\n");
  }
  return 0;
}