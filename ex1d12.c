#include <stdio.h>

int main(void) {

  int c;
  int nc;

      while ((c = getchar()) != EOF) {
	//nc++;
	if(c == ' ')
         printf("\n");
	printf("%c", c);
	
  }


    
    return 0;
}
