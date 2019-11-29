/* compare two strings and return negative
if not the same
*/

#include <stdio.h>

int strcomp(char *, char *);

int main(void) {
  char s[100];
  char t[100];
  int r;
  
  printf("Enter a word ");
  scanf("%s",s);
  printf("Enter word to compare ");
  scanf("%s",t);

  r = strcomp(s,t);

  if(r == 0){
    printf("strings are the same %d", r);
  } else {
    printf("strings differ %d", r);
  }

  return 0;
}

int strcomp(char *s, char *t){
  for (; *s == *t; s++, t++)
    if (*s == '\0')
      return 0;
  return *s - *t;
}

  
