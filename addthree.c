/* An example where value of a variable is not changed by function
and where pointers would be used instead
*/

#include <stdio.h>

void addthree(int);

int main(void) {
  int stp = 0;
  int a = 0;
  printf("value before function is %d\n",a);   //output 0
  addthree(a);
  printf("value after function is %d\n",a);   // output 0 as function did not change value

  scanf("%d", &stp);
  return 0;
  }

void addthree(int a) {
  a = a + 3;
  printf("value inside the function %d\n", a);    // output 3
}
