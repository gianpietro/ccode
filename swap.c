/* this is an example to show that the values
of the variables a and b cannot be changed by
the function swap and is a good example
of why pointers need to be used
*/

#include <stdio.h>

void swap(int, int);

int main(void) {
  int stp;
  int a = 4;
  int b = 8;

  printf ("%d %d\n", a,b);
  swap(a,b);
  printf ("%d %d\n", a,b);

  scanf("%d", &stp);
  return 0;
}

void swap(int a, int b) {
  int tmp = a;
  a = b;
  b = tmp;

}
 
