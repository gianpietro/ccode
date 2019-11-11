/*shell sort */
#include <stdio.h>

#define ANSI_COLOR_RESET "\x1b[0m"

void shellsort(int *, int);

int main(void) {

  int i, k;
  int iarray;
  
  int array[] = {3,5,7,8,9,11,1,4};
  iarray = sizeof(array)/sizeof(int);
  printf("size of array %d\n", iarray);

  for (i=0; i<iarray; ++i){
    printf("%d ", array[i]);
  }

  shellsort(array, iarray);
  printf("\n");
  
  for (i=0; i<iarray; ++i){
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}

void shellsort(int v[], int n){
  printf("\n");
  int gap, i, j, temp;
  int m;
  
  printf("%d\n",n);

  for (gap = n/2; gap > 0; gap /=2){
    printf("--------------------------------\n");
    printf("gap outer loop %d\n", gap);
    printf("--------------------------------\n");
    for (i=gap; i < n; i++){
      printf("i middle loop %d\n", i);
      printf("gap middle loop %d\n", gap);
      printf("\n");
      for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap){
	printf("i inner loop %d\n", i);
	printf("j inner loop %d\n", j);
        printf("gap inner loop %d\n", gap);
        printf("v[j] inner loop %d\n", v[j]);
        printf("v[j+gap] inner loop %d\n",v[j+gap]);
        temp = v[j];
        printf("temp inner loop %d\n", temp);
        v[j] = v[j+gap];
        printf("v[j]=v[j+gap]inner loop %d\n", v[j]);
        v[j+gap] = temp;
	for (m=0; m<n; ++m){
	  printf("\033[5;32m %d ", v[m]);
	  
         }
	printf(ANSI_COLOR_RESET);
   }
       
       printf("\n");
    }
   
  }
  
}
  
