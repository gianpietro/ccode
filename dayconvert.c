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
int enter_date(int, int, int);
char *month_name(int);

int main(void) {
  int d;
  int yr, mth, dy;
  int c = 0;

  while (c == 0){
    printf("Enter the year ");
    scanf("%d", &yr);
    printf("Enter the month as a number ");
    scanf("%d", &mth);
    printf("Enter the day as a number ");
    scanf("%d", &dy);
    c = enter_date(yr, mth, dy);
  }
  
  d = day_of_year(yr, mth, dy);
  month_day(yr, d, &mth, &dy);

  return 0;
}

int day_of_year(int year, int month, int day) {
  int i, leap;
  leap = year%4 == 0 && year%100 !=0 || year%400 == 0;
  printf("leap %d\n", leap);
  for (i=1; i < month; i++)
      day += daytab[leap][i];
     printf("day_of_year %d\n", day);
      return day;
}

/* Function month_day
Takes the yearday from the day_of_year function
e.g. 15/3/2019 is yearday 74
Then it goes thoough each month and if the yearday is greater
than number of days in month it will subtract the number of days in the
the month from yearday. It will then reach the month and day of month
In example mentioned January has 31 days so 74 - 31 = 43
February has 28 (or 29 leap) so 43 - 28 = 15
March has 31 days so yearday < March so displays March 15th
*/
void month_day(int year, int yearday, int *pmonth, int *pday){
  int i, leap;
  leap = year%4 == 0 && year%100 !=0 || year%400 == 0;
  for (i = 1; yearday > daytab[leap][i]; i++){
    yearday -= daytab[leap][i];
    printf("yearday %d\n", yearday);
    printf("days in month %d\n", daytab[leap][i]);
  }
  
  *pmonth = i;
  *pday = yearday;

  printf("Month name %s\n", month_name(*pmonth));      // use function month_name could pass in i instead
  printf("month %d\n",*pmonth);
  printf("day %d\n",*pday);
}

int enter_date(int year, int month , int day){
  int j, leap, ckday;
  leap = year%4 == 0 && year%100 !=0 || year%400 == 0;
  j = month;
  ckday = daytab[leap][j];
  printf("check day %d\n", ckday);
  if (day > ckday){
    printf("ERROR re-enter the date\n");
    
    return 0;
  }else{
    printf("GOOD\n");
    return 1;
  }
}

/* month_name: return name of the n-th month */
char *month_name(int n) {
   static char *name[] = {
    "Illegal month",
    "January", "February", "March",
    "April", "May", "June","July",
    "August", "September","October",
    "November", "December"			 
  };
  return (n < 1 || n > 12) ? name[0]: name[n];
}
