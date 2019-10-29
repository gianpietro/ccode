#include <stdio.h>

int main(void) {
  
  int c, nl;
  c = 0;

  nl = 0;
  while ((c = getchar()) != EOF) {
    if ( c == '\n') {
      nl++;
      printf ("%d\n", nl);
      printf("Integer of c %d\n",c);
      printf("Char of c %c\n", c);
      getchar();
      c = getchar();
    }
  }
  return 0;
}
