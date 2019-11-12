/*shell sort */
#include <stdio.h>

//#define ANSI_COLOR_RESET "\x1b[0m"

void shellsort(int *, int);                                  // prototype for function shellSort
void shellsortcompact(int *, int);

int main(void) {
  int i, k;
  int iarray;
  char c;

  int array[] = {3,5,7,8,9,11,1,4,45,5,43,65,67,78,12,23,34,32,6,57,3,68,98,76,56};                           // array items
  iarray = sizeof(array)/sizeof(int);                         // size in bytes divided by int to get number of items          
  printf("size of array %d\n", iarray);

  for (i=0; i<iarray; ++i){                                   // print array before sort
    printf("%d ", array[i]);
  }
  printf("\n");

  printf("Run program with variable value display y/n ");
  scanf("%c",&c);
  if (c == 'y'){
    shellsort(array, iarray);                                 // call to function shellSort
    printf("\n");
  } else {
    shellsortcompact(array, iarray);
    printf("\n");
  }
  
  for (i=0; i<iarray; ++i){                                   // print array after sort
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}


void shellsort(int v[], int n){
  printf("\n");
  int gap, i, j, temp;
  int m;
    
  printf("Number of array items passed to function %d\n",n);

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
	  // printf("\033[5;32m %d ", v[m]);
	  printf("%d ", v[m]);
         }
	// printf("\n");
	// printf(ANSI_COLOR_RESET);
    }
       // printf("\n");
   }
  }
}

  void shellsortcompact(int v[], int n){
  printf("\n");
  int gap, i, j, temp;
  int m;
    
  printf("Number of array items passed to function %d ",n);
  printf("\n");

  for (gap = n/2; gap > 0; gap /=2){
    for (i=gap; i < n; i++){
      for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap){
	temp = v[j];
        v[j] = v[j+gap];
        v[j+gap] = temp;
	for (m=0; m<n; ++m){
	  printf("%d ", v[m]);
        }
	printf("\n");
     }
   }
 }
}
  
