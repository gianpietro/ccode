/* Reading data from an external text file
*/

#include <stdio.h>

int main(void) {
  int c;
  int i;
  int num;
  //  int done, message;
  FILE *fp;
  char str[100];

  fp = fopen("data1.txt", "r");

  // fgets (str, 60, fp);
  fgets(str, sizeof(str), fp);
  puts(str);
    
  /*
  fscanf(fp, "%d", &c);
  printf("there are %d numbers in file\n", c);

  for (i=0; i<c; i++){
    fscanf(fp, "%d", &num);
    printf("%d\n", num);
  }
  */
  //  while((c = getc(fp)) != EOF)
  //  printf("%d ", c);

  /*
  while (!done) {
  message = fscanf(fp, "%d", &c);
  if(message == EOF){
    done = 1;
  } else {
    printf("%d", c);
  }
  }
  */
    

  fclose(fp);

  return 0;
}

  
  
  
