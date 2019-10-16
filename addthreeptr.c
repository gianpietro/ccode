/* this example uses a pointer so the variable value
is now changed by the function
*/
#include <stdio.h>

void addthree(int *);

int main(void) {
  int stp = 0;
  int a = 0;
  printf("value before function is %d\n",a);    // output is 0
  addthree(&a);
  printf("value after function is %d\n",a);     // outout is 3

  scanf("%d", &stp);
  return 0;
  }

void addthree(int *a) {
  *a = *a + 3;
  printf("value inside the function %d\n", *a);   // output is 3
}
