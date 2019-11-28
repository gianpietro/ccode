/* copy a stated number of digits from string 1 into
a second string
*/

#include <stdio.h>

void strcopy(char *, char *, int);

int main(void) {
  int stp;
  char s[100];
  char t[100];
  int i;

  printf("Enter a word ");
  scanf("%s",s);
  printf("Enter number of characters to copy ");
  scanf("%d",&i);

  strcopy(s, t, i);

  printf("value %s\n", t);

  scanf("%d", &stp);

  return 0;
}

void strcopy(char *x, char *y, int n){

  /* int cnt;
  for(cnt=0; cnt < n; cnt++){
  *y++ = *x++;
  }
  */


    while (n > 0) {
    *y++ = *x++;
    --n;
  }
  
    
}
