#include <stdio.h>
#define MAXLINE 1000

int getl(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main() {
  char line[MAXLINE];
  int found = 0;

  while (getl(line, MAXLINE) > 0)
    if (strindex(line, pattern) >= 0) {
      printf("%s", line);
      found++;
    }
    return found;
}

/* Function to enter the string value on which to search 
   for match. If '\n' adds this to the string and then adds
   the eol indicator for string '\0'. Returns an integer
   which is used in while loop in main.   
*/

int getl(char s[], int lim){
  int c, i;

  i = 0;
  while(--lim > 0 && (c=getchar()) != EOF && c != '\n')
    s[i++] = c;    
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

/* If match is found will return value of i which will be >= 0
   and so print the line. If no match will return -1 and so no 
   print out
*/

int strindex(char s[], char t[]){
  int i, j, k;

  for (i = 0; s[i] != '\0'; i++){
    for (j=i, k=0; t[k] != '\0' && s[j]==t[k]; j++, k++)
      ;
    if (k>0 && t[k] == '\0')
      return i;
  }
  return -1;
}
