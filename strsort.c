/* Some pointers are variables themselves, they can be stored in arrays
like other variables
*/

#include <stdio.h>
#include <string.h>

#define MAXLINES 500                                                        // max lines which can be stored  
#define MANLEN 100                                          

char *lineptr[MAXLINES];                                                    // pointers to text lines, pointer stored in array

int readlines(char *lineprt[], int nlines);                                 // notation for pointer stored in array
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int getline(char *, int);

char *alloc(int);

int main(void){

  int nlines;                                                                // number of input lines read           

  if ((nlines = readlines(lineptr, MAXLINES)) >=0) {
       qsort(lineptr, 0, nlines-1);
       writelines(lineptr, nlines);
       return 0;
   } else {
       printf("error: input too big to sort \n");
       return 1;
  }

return 0;
}

/* getline: read a line into s, return length */
int getline(char s[],int lim)
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

/* readlines: read input nlines */
int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = getline(line, MAXLEN)) > 0)
    if(nlines >= MAXLINES || p = alloc(len) == NULL)
       return -1;
    else {
      line[len-1] = '\0';
      lineptr[nlines++] = p;
    }
  return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines){
  int i;

  for(i=0;i < nlines; i++)
    printf("%s\n", lineptr[i]);
}
