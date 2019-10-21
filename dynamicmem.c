/* in this example we look at dynamic memory which
is stored in the heap. Memory is allocated and
then freed. Note the use of stdlib.h
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int stp;
  int *a, *b, *c;
  // allocate the dynamic memory, recommended to cast this for the type being used
  // which in this case is an int of pointer type (int *)
   a = (int *)malloc(sizeof(int));

  // this is the newer recommended way to use malloc for C programs
  //a = malloc(sizeof *a);
  *a = 58;
  printf("I stored var a %d at the memory location %p \n", *a, a);
 b = (int *)malloc(sizeof(int));
 //b = malloc(sizeof *b);
  *b = 35;
  printf("I stored var b %d at the memory location %p \n", *b, b);

  // when no longer required we can free the memory location
  //** IMPORTANT - if I free memory allocation for variable a at this point **
  //the memory allocated will be used by the variable c
  //when I print the value and location of variable a below it will
  //output value for variable c
  free(a);  //NOTE 1
  // can we still access the variable a value and address?
   c = (int *)malloc(sizeof(int));
  *c = 84;
  printf("I stored var c %d at the memory location %p \n", *c, c);
  printf("I stored var a %d at the memory location %p \n", *a, a); // NOTE 1- gives value of c if use free(a) above
  //free(a);  // should keep memory allocated for a and release allocation here to avoid confusion
  free(b);
  free(c);
  scanf("%d", &stp);
  return 0;
}
