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
  return ptr;
}


  
