#include <stdio.h>

int main(void) {

  int array[] = {1,2,3,4};
  int *ptr;

  ptr = array;

  printf("%d\n",array[0]);
  printf("%p\n",&array[0]);

  *ptr = 10;

  printf("%d\n",array[0]);
  printf("%p\n",&array[0]);

  *array = 7;

  printf("%d\n",array[0]);
  printf("%p\n",&array[0]);

  ptr+=3;
  printf("%d\n",*ptr);
  printf("%p\n",ptr);
  return 0;
}
