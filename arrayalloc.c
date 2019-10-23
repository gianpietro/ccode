/* This example uses a array initiated as a pointer *array
It does not have a specified size and I use a function to  malloc 
a size for the array specified by an integer entered by user 

 */
#include <stdio.h>
#include <stdlib.h>

// prototype for functions which will be used by main program
int * allocateIntArray(int);
double findAverage(int *, int);

int main(void) {
  int stp;
  int num,i;
  int *array;
  double avg;

  num = 0;
  i = 0;
  avg = 0;

  printf("Enter number of items to go into array ");
  scanf("%d", &num);

  // use function to allocate memory space for dynaic array
  array = allocateIntArray(num);

  // check it the array is NULL if it is then exit the program
  if(array == NULL) {
    printf("malloc of size %d failed!\n", num);   // could also call perror here
    exit(1);   // or return an error to caller
   }

  // enter the values for the array to store
  for(i=0; i<num;i++){
    scanf("%d",array+i);
  }

  // print out the values whcih the array is storing
  for (i=0;i<num;i++){
    printf("array values %d\n",array[i]);
  }

  // call fundtion to find average value of integers in array
  avg = findAverage(array, num);

  printf("The average for items is array %.2f\n", avg);
   
  
  // free the mmemory allocation for the array
  free(array);
  
  scanf("%d",&stp);
  return 0;
}


int * allocateIntArray(int num) {
  int * ptr;

  /* To allocate the memory to the *ptr the EDX course recommended 
     using a cast infron of the malloc function and also how to
     use sizeof(int)   
    
     ptr  = (int *) malloc(num*sizeof(int));

     From various discussions on line it seems that with C programming
     the cast is no longer required as defaults to void* and will
     take on the type required without the cast having to be assigned.

     Also recommended a different way of using sizeof as show in code below 
     This is not the case for C++ which should stick to previous method
 
     ptr = malloc(sizeof * ptr * num);

  */

  // I will stick with the EDX course method as this seems to be the
  // method used in C standard documentation
  ptr = (int *)malloc(num * sizeof(int));

  // ptr = NULL;    test code DELETE

  return ptr;
}

double findAverage(int * ptr, int n) {
  double avg;
  int i;
  avg = 0;
HEAD


   for (i=0; i<n; i++) {
     avg += ptr[i];
   }

   return avg/n;
}

7b142ca4c96824be2004291bd673cd1ccedbdec7


  
  
