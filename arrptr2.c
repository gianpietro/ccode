#include <stdio.h>  
int main() {
  int stp;
  int array[] = {4, 6, 12, -5, -7, 3, 1, 8, -10};
  int *ptr1, *ptr2;
  ptr1 = array+2;     
  ptr2 = &ptr1[5];   
  printf("%d\n", *ptr1);  // output is digit 12 in array
  printf("%d\n", *ptr2);  // output is digit 8 in array
  printf("The address is %p\n", *(ptr1+1)); //this will print out the address due to %p
  printf("The value is %d\n", *(ptr1+1)); //this will print out the value sue to %d -- output -5
  printf("The address is %p\n", *(ptr2-3)); //this will print out the address due to %p
  printf("The value is %d\n", *(ptr2-3)); //this will print out the value due to %d -- output -7
  scanf("%d", &stp);
  return 0;

 }
