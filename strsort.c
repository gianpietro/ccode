/* Some pointers are variables themselves, they can be stored in arrays
like other variables
*/

#include <stdio.h>
#include <string.h>

#define MAXLINES 100                                       // max lines which can be stored  
#define MAXLEN 100
#define ALLOCSIZE 10000                                    // alloc function size of available space


char *lineptr[MAXLINES];                                   // pointers to text lines, pointer stored in array

int readlines(char *lineprt[], int nlines);                // notation for pointer stored in array
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int getl(char *, int);

char *alloc(int);
static char allocbuf[ALLOCSIZE];                           // storage for alloc
static char *allocp = allocbuf;                            // next free position

void swap(char *[], int, int);
int strcomp(char *, char *);
void strcopy(char *, char *);

int main(){

  int nlines;                                              // number of input lines read           

  if ((nlines = readlines(lineptr, MAXLINES)) >=0) {
       qsort(lineptr, 0, nlines-1);
       writelines(lineptr, nlines);
       return 0;
   } else {
       printf("error: input too big to sort \n");
       return 1;
  }

  //return 0;
}

char *alloc(int n) {
  if (allocbuf + ALLOCSIZE - allocp >= n) {
    allocp += n;
    return allocp - n;
  } else {
    return 0;
  }
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

/* readlines: read input nlines */
int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = getl(line, MAXLEN)) > 0)
    if(nlines >= MAXLINES || (p = alloc(len)) == NULL)
       return -1;
    else {
      line[len-1] = '\0';
      strcopy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines){
  int i;

  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}

/* swap: interchange v[i] and v[j] */
void swap (char *v[], int i, int j) {
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void qsort (char *v[], int left, int right) {
  int i, last;

  if (left >= right)                                       // do nothing if array contains
    return;                                                // fewer than two elements
  swap(v, left, (left + right)/2);
  last = left;
  for (i = left+1; i <= right; i++){
    printf("i %d\n", i);                                  // debug code remove with for{}  
    if (strcomp(v[i], v[left]) < 0){   
      //  printf("i= %d left = %d\n", i,left); 
      //  printf("string v[i]%s  v[left] %s\n", v[i],v[left]);       // debug code remove with if{} 
        swap(v, ++last, i);
    }
  }
  swap(v, left, last);
  qsort(v, left, last-1);
  printf("i= %d left = %d\n", i,left); 
  printf("string v[i]%s  v[left] %s\n", v[i],v[left]);
  qsort(v, last+1, right);
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcomp(char * s, char * t) {
  for ( ; *s == *t; s++, t++)
    if (*s == '\0')
      return 0;
  return *s - *t;
}

void strcopy(char *s, char * t){
  while ((*s++ = *t++) != '\0')
    ;
}

            
