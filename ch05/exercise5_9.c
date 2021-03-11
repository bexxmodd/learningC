#include <stdio.h>

static char daytab[] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
char *dp = &daytab;

/* set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    if (month < 1 || month > 12)
        return day;
    int leap, i;
    leap = (year%4 == 0 && year%100 != 0 || year%400 == 0) ? 0 : 1;
    for (i = 1; i < month; i++)
        day += *dp++;
    return day + leap;
}

/* set month, day from day of year */
void month_day()
{
    return;
}