/* Page 25 The C programming Language
   In C, all function arguments are passed "by value".
   This means that the called function is given the 
   values of its arguemnts in temporary variables
   rather than the originals.
   ("Call by reference" is when routine has access to 
     the original argument, not a local copy")
   Exceptions:
   Other option in C is to use a pointer to the variable.
   When the name of array is used as an argument, the value 
   passed to the function is the location or address of the
   beginning of the array, there is no copying of array elements.
 */

#include <stdio.h>

int power(int, int);					// prototype of function

int main(void) {
  int stp;
  int i;
  int r;

  for (i=0; i< 10; ++i){
    printf("%d %d %d\n", i, power(2,i), power(-3,i));   // passing arguments in function call
  }

  r = power(5,3);
  printf("%d\n", r);
  scanf("%d", &stp);
  return 0;
}

int power(int base, int n){    				// function parameters
  int i, p;
  p = 1;
  for(i = 0; i < n; ++i){
    p = p * base;
  }
  return p;
}

