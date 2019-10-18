/* this is looking at multi dimensional arrays and how
they can be utilised with pointer arithmatics
*/

#include <stdio.h>

int main(void) {
  int stp;
  short a[3] = {10, 11, 12};
  short b[2] = {22, 23};
  short c[3] = {35, 38, 39};
  short * arrays[3] = {a,b,c};
  int i = 0;

  printf("%d\n", *arrays[0]);   // output is 10
  
  *arrays[0] = 15;
  printf("%d\n", *arrays[0]);   // output is 15

  *(arrays[0]+1) = 17;
  printf("%d\n", *(arrays[0]+1));   // output is 17
  
  
  for (i=0; i<3; i++) {
    printf("values in array a %d\n", *(arrays[0]+i));  // output 15,17,12
  }
  
 for (i=0; i<2; i++) {
    printf("values in array b %d\n", *(arrays[1]+i));  // output 22, 23
  }

 scanf("%d", &stp);
  return 0;
}
