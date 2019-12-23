#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define ALLOCSIZE 10000
#define MAXLEN 100
char *lineptr[MAXLINES];
static char allocbuf[ALLOCSIZE];                           // storage for alloc
static char *allocp = allocbuf;                            // next free position

int strcomp(char *, char *);
void strcopy(char *, char *);

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsortv(void *lineptr[], int left, int right,
	   int (*comp)(void*, void*));

int numcmp(char *, char *);
void swap(void *[], int, int);
char *alloc(int);
int getl(char *, int);

int main(int argc, char *argv[]){
  int nlines;
  int numeric = 0;

  if (argc > 1 && strcomp(argv[1], "-n") == 0)
    numeric = 1;
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    // the first argument is of type void* lineptr[], which is equivalent to void** lineptr
    qsortv((void**) lineptr, 0, nlines-1,(int(*)(void*,void*))(numeric ? numcmp : strcomp));
    printf("numeric value %d\n", numeric);
  writelines(lineptr, nlines);
  return 0;
} else {
  printf("input too big to sort\n");
  return 1;
    }
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

void qsortv(void *v[], int left, int right,
	    int (*comp)(void *, void *)) {
  int i, last;
  void swap(void *v[], int, int);
  if (left >= right)                                       
    return;                                                
  swap(v, left, (left + right)/2);
  last = left;
  for (i = left+1; i <= right; i++)
    if ((*comp)(v[i], v[left]) < 0)  
        swap(v, ++last, i);
  swap(v, left, last);
  qsortv(v, left, last-1, comp);
  qsortv(v, last+1, right,comp);
}

/* numcmp: compare a1 and a2 numerically */
int numcmp(char *s1, char *s2) {
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
      return -1;
    else if (v1 > v2)
      return 1;
    else
      return 0;
  }

  
/* swap: interchange v[i] and v[j] */
void swap (void *v[], int i, int j) {
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
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

