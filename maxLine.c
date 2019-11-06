#include <stdio.h>

#define MAXLINE 1000	       				// maximum input line size

int getline(char *, int);
void copy(char *, char *);

int main(void){
  int stp;
  int j, k;
  int len;            	     				// current line length
  int max;						// maximum length seen so far
  char line[MAXLINE];					// current input line
  char longest[MAXLINE];				// longest line save here

  max = 0;
  k = 0;
  while ((len = getline(line, MAXLINE)) > 0)
    if (len > max){
      max = len;
      copy(longest, line);
    }
  if (max > 0)						// there was a line
    printf("%s\n", longest);  
   
  for (j=0; j <= max; ++j){						 // loop to count number of characters
    if (longest[j] != ' ' && longest[j] != '\n' && longest[j] != '\0'){  // excluding spaces, line breaks and nulls
    ++k;
    }
  }
  printf("Number of characters %d\n", k);
 
  scanf("%d", &stp);
 return 0;
}

int getline(char s[], int lim){
  int c, i;
  
  for (i=0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if ( c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';						// inserts null char at end of array
  				       			// similar to string constant which inserts null at end
  return i;   
}

void copy(char to[], char from[]){
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}

