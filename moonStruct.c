#include <stdio.h>
#include <stdlib.h>

struct matrix{
  char direction[20];
  int  coordinate;
};

void inputStructure(struct matrix *);
void pStruct(struct matrix *);
void printStructure(struct matrix *, int);

int main (void) {
  int stp;
  int i;
  int num;

  struct matrix *moon;

  printf("Enter number of points required :");
  scanf("%d", &num);
  moon = (struct matrix *)malloc(num * sizeof(struct matrix));
  for (i=0;i<num;i++){
    inputStructure(&moon[i]);
  } 

  printStructure(moon, num);

  free(moon);

  scanf("%d", &stp);
  return 0;
}

void inputStructure(struct matrix *moon){
  printf("Enter direction description :");
  scanf("%s", moon->direction);
  printf("Enter number for coordinate :");
  scanf("%d", &moon->coordinate);   
}

void pStruct(struct matrix *moon) {
  printf("POINTER Moon co-ordinate direction %s , point %d \n", moon->direction, moon->coordinate);
}

void npStruct(struct matrix moon){
  printf("NOTPOINTER Moon co-ordinate direction %s , point %d \n", moon.direction, moon.coordinate);
}

void printStructure(struct matrix *ptr, int co){
  int i = 0;
  for (i=0;i<co;i++){
    pStruct(ptr+i);
    npStruct(ptr[i]);
  } 
}
