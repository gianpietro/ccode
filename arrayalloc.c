#include <stdio.h>
#include <stdlib.h>

int * allocateIntArray(int);
double findAverage(int *, int);

int main(void) {
  int num,i;
  int *array;

  printf("Enter number of items to go into array ");
  scanf("%d", &num);
  array = allocateIntArray(num);
  if(array == NULL) {
    printf("malloc of size %d failed!\n", num);   // could also call perror here
    exit(1);   // or return an error to caller
   }
  for(i=0; i<num;i++){
    scanf("%d",array+i);
  }
  for (i=0;i<num;i++){
    printf("array values %d\n",array[i]);
  }

  free(array);
  
  return 0;
}


int * allocateIntArray(int num) {
  int * ptr;
  ptr  = (int *) malloc(num*sizeof(int));
  //ptr = NULL;    test code DELETE
  return ptr;
}


  
