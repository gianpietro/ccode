#include <stdio.h>

void shellsort(int *, int);

int main(void) {

  int i;
  int y;
  y=6;
  
  int array[] = {3,5,7,8,9,1};

  for (i=0; i<y; ++i){
    printf("%d ", array[i]);
  }

  shellsort(array, y);
  printf("\n");
  

  return 0;
}

void shellsort(int v[], int n){
  printf("\n");
  int gap, i, j, temp;
  printf("%d\n",n);
  for (gap = n/2; gap > 0; gap /=2)
    //printf("gap outer loop %d\n", gap);
    for (i=gap; i < n; i++)  
      for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap){
	printf("i middle loop %d\n", i);
	printf("j middle loop %d\n", j);
        printf("gap middle loop %d\n", gap);
        printf("v[j] middle loop %d\n", v[j]);
        printf("v[j+gap] middle loop %d\n",v[j+gap]);
   }
  
}
  
