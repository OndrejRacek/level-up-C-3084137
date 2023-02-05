#include <stdio.h>

double FI(int CallN, int MAXrec)
{
  double result;
  if (CallN >= MAXrec)
  {
    result = 1;
  }
  else
  {
    result = 1 + 1 / FI(CallN + 1, MAXrec);
  }
  // printf("Call %d result = %f", CallN, result);
  return result;
}

int main()
{
  printf("FI = %f", FI(0, 100));
}