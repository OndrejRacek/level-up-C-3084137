#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#define WEEK_NDAYS 7
#define YEAR_MONTHS 12
#define MONDAY_INDX 1

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

char *ordinal(int n)
{
  int u1;
  u1 = n % 10;
  if (u1 == 11 | u1 == 12 | u1 == 13)
  {
    return "th";
  }
  else
  {
    if (u1 == 1)
      return "st";
    else if (u1 == 2)
      return "nd";
    else if (u1 == 3)
      return "rd";
    else
      return "th";
  }
}

const char *month_names[] = {
    "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

const char *day_names[] = {
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

const int month_ndays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
  time_t now;
  struct tm *today;

  int wkday1, mday1, mon1, year1, monthcur_ndays;
  int wkday2, mday2, mon2, year2;
  int days2Mon;

  /* gather time details */
  // time(&now);
  now = (time_t)951766435;
  today = localtime(&now);

  /* output today's info */

  wkday1 = today->tm_wday; // base 0 index
  mon1 = today->tm_mon;
  mday1 = today->tm_mday;
  year1 = today->tm_year + 1900;

  printf("Today is %s, %s, %d%s, %d\n",
         day_names[wkday1],
         month_names[mon1],
         mday1,
         ordinal(mday1),
         year1);

  monthcur_ndays = month_ndays[mon1] + ((mon1 == 1 ? (leapyear(year1) ? 1 : 0)
                                                   : 0));
  printf("There are %d days in %s\n", monthcur_ndays, month_names[mon1]);

  wkday2 = 1;
  days2Mon = (WEEK_NDAYS + MONDAY_INDX - wkday1) % WEEK_NDAYS;
  days2Mon = (days2Mon == 0 ? 7 : days2Mon);
  mday2 = (days2Mon + mday1) % monthcur_ndays;
  mon2 = (mon1 + (days2Mon + mday1) / monthcur_ndays) % (YEAR_MONTHS - 1);
  // mon2 = (mon1 + (WEEK_NDAYS - wkday1 + mday1) / monthcur_ndays);
  // mon2 = mon2 % YEAR_MONTHS;
  year2 = year1 + (mon1 + (days2Mon + mday1) / monthcur_ndays) / (YEAR_MONTHS - 1);

  printf("Next Monday is %s, %d%s, %d\n",
         month_names[mon2],
         mday2,
         ordinal(mday2),
         year2);
  return 0;
}