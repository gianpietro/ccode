#include <stdio.h>

int main(void) {

  #define IN 1
  #define OUT 0

  int c, nl,nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;

  /* to exit the program and get an EOF result press ctl+D keys
     the printf statement will then execute */
  
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
    
    printf("New lines %d Number of words %d  Number of chars including spaces and new lines %d\n", nl, nw, nc);

    return 0;
}

 
  
