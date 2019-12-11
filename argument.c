/* Program which uses the argc and agrv in the main
function to search for a pattern in a string and retrun that
string if pattern found.
The first argument entered is the patter to find
the subsequent arguments are the strings in which to
search for the pattern */

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getl(char *line, int max);

/*find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[]) {
  char line[MAXLINE];
  int found = 0;

  if (argc != 2)
    printf("Usage: find pattern\n");
  else
    while (getl(line,MAXLINE) > 0)
      if (strstr(line, argv[1])  != NULL) {
	  printf("%s", line);
	  found++;
	}
	return found;
}

/* getline: read a line into s, return length */
int getl(char s[],int lim)
{
  int c, i;
  for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
return i;
}
