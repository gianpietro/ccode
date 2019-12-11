/* Enter a date and the program will work out which day
of the year it is, taking into account leap years
e.g.31 march in leap year is 61st day while 60th day in non leap year
*/

#include <stdio.h>

 static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
  };


int day_of_year(int, int, int);
void month_day(int, int, int *, int *);

int main(void) {
  int stp;  
  int d;
  int *x, *y;
  int yr, mth, dy;
  //  mth = 3;
  //  dy = 1;
  
  printf("Enter the year ");
  scanf("%d", &yr);
  printf("Enter the month as a number ");
  scanf("%d", &mth);
  printf("Enter the day as a number ");
  scanf("%d", &dy);

  d = day_of_year(yr, mth, dy);
  month_day(yr, d, &mth, &dy); 

  scanf("%d", &daytab);
  
  return 0;
}

int day_of_year(int year, int month, int day) {
  int i, leap;
  leap = year%4 == 0 && year%100 !=0 || year%400 == 0;
  for (i = 1; i < month; i++){
    if (day > 31){
      printf("Error in day ");
    }else{
      day += daytab[leap][i];
    }
  }
  printf("day_of_year %d\n", day);
  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday){
  int i, leap;
  leap = year%4 == 0 && year%100 !=0 || year%400 == 0;
  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];
  *pmonth = i;
  *pday = yearday;

  printf("month %d\n",*pmonth);
  printf("day %d\n",*pday);
}
