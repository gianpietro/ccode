/* this example demonstrates how pointers are used
to change values of variables from the function swap
and fixes the issue encounterd in the code swap.c
*/


#include <stdio.h>

void swap(int *, int *);

int main(void) {
  int stp;
  int a = 4;
  int b = 8;

  printf ("%d %d\n", a,b);
  swap(&a,&b);
  printf ("%d %d\n", a,b);

  scanf("%d", &stp);
  return 0;
}

void swap(int * a, int * b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;

}
