#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#define WEEK_NDAYS 7
#define YEAR_MONTHS 12
#define MONDAY_INDX 1

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
  time_t now, then;
  struct tm *today, *Monday, usrdttm1;

  int days2Mon;

  int y1, m1, d1, h1, mn1, sc1;

  scanf("%d-%d-%d %d:%d:%d", &y1, &m1, &d1, &h1, &mn1, &sc1);
  // printf("echo %d-%d-%d %d:%d:%d\n", y1, m1, d1, h1, mn1, sc1);

  usrdttm1.tm_year = y1 - 1900;
  usrdttm1.tm_mon = m1 - 1;
  usrdttm1.tm_mday = d1;
  usrdttm1.tm_hour = h1;
  usrdttm1.tm_min = mn1;
  usrdttm1.tm_sec = sc1;
  // usrdttm1.tm_wday = 1;
  // usrdttm1.tm_yday = 59;
  usrdttm1.tm_isdst = -1;

  /* gather time details */

  // time(&now);
  // now = (time_t)951766435;
  now = mktime(&usrdttm1);
  today = localtime(&now);

  /* output current date and time*/

  printf("Today is %s, %s, %d%s, %d %2d:%2d:%2d\n",
         day_names[today->tm_wday],
         month_names[today->tm_mon],
         today->tm_mday,
         ordinal(today->tm_mday),
         today->tm_year + 1900,
         today->tm_hour,
         today->tm_min,
         today->tm_sec);

  days2Mon = (WEEK_NDAYS + MONDAY_INDX - today->tm_wday) % WEEK_NDAYS;
  days2Mon = (days2Mon == 0 ? 7 : days2Mon);

  then = now + (days2Mon * 24 * 60 * 60);
  Monday = localtime(&then);

  printf("Next Monday is %s, %d%s, %d %2d:%2d:%2d\n",
         month_names[Monday->tm_mon],
         Monday->tm_mday,
         ordinal(Monday->tm_mday),
         Monday->tm_year + 1900,
         Monday->tm_hour,
         Monday->tm_min,
         Monday->tm_sec);
  return 0;
}