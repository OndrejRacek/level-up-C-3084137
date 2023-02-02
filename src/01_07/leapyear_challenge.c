#include <stdbool.h>
#include <stdio.h>

#define YEAR_START 1582
#define YEAR_END 2101

bool leapyear(int year)
{
  if (((year % 4 == 0) && !(year & 100 == 0)) || (year % 400 == 0))
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  for (int year = YEAR_START; year <= YEAR_END; year++)
  {
    if (leapyear(year))
    {
      printf("%d", year);
      if (year < YEAR_END)
        printf(", ");
    }
  }
  return 0;
}