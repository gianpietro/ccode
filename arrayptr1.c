#include <stdio.h>

int main(void) {
  int stp;
  int *ptr;
  int i;
  int arr[3] = {12,14,16};
  
  for (i = 0; i < 3; i++) {
    printf("%d\n", arr[i]);
  }
   
  ptr = arr;

  *ptr = 5;
  *(ptr+1) = 8;
  *(ptr+2) = 3;

 for (i = 0; i < 3; i++) {
    printf("%d\n", arr[i]);
  }

  
  scanf("%d", &stp); 

  return 0;
}
