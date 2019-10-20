/* In this example a function with void return is used to
update the variable in the main program. The address of variable
sum is passed to the function which has a pinter to the address
and value of pointer updated. 
 */

#include <stdio.h>

void addint(int, int, int *);

int main(void) {
  int a, b, sum;
  a = 0;
  b = 0;
  sum = 0;

  printf("Enter the first integer value ");
  scanf("%d", &a);
  printf("Enter the second integer value ");
  scanf("%d", &b);

  addint (a,b, &sum);

  printf ("First number entered %d Second number entered %d TOTAL is %d\n", a,b,sum);

  return 0;
}

void addint (int x, int y, int *total) {

  *total = x + y;
}
