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
  
  for (i=0; i<y; ++i){
    printf("%d ", array[i]);
  }

  return 0;
}

void shellsort(int v[], int n){
  printf("\n");
  int gap, i, j, temp;
  printf("%d\n",n);
  for (gap = n/2; gap > 0; gap /=2){
    printf("gap outer loop %d\n", gap);
    for (i=gap; i < n; i++){
      printf("i middle loop %d\n", i);
      printf("gap middle loop %d\n", gap);
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
   }
    }
  }
  
}
  
