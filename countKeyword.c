/* This example uses a structure to store a list of keywords
and the struct has a count value to store the number of times
that keyword is entered into the terminal.
The user types words in and the program counts
any keywords which are found in the structure and updates the keytab[].count
for that word by 1 each time the word is entered. The word and count (total)
is displayed when EOF reached. */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct key {
  char *word;
  int count;
} keytab[] =
  {
   "auto", 0,
   "break", 0,
   "case", 0,
   "char", 0,
   "const", 0,
   "continue", 0,
   "default", 0,
  };	      


#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(struct key))

int getword(char *, int);
int binsearch(char *, struct key *, int);

int getch(void);
void ungetch(int);
char buf[10];
int bufp = 0;

int main ()
{
  int n;
  char word[MAXWORD];

  while (getword(word,MAXWORD) != EOF)
    if (isalpha(word[0]))
/* A word is entered by the user and the program then uses binsearch
subroutine to see if that word is in the struct keytab
If it is it will update the count value for that word
That is how it nanages to count how any times each word is entered
For example I enter the value const then keytab[n].count++ 
will update the count value in struct for const to 1
If const is entered again at some point then the count value
for that word will be incremented and that is how it
displays the total number of times const has been entered */
      if((n = binsearch(word,keytab,NKEYS)) >= 0)
	 keytab[n].count++;
  for (n = 0; n < NKEYS; n++)
    if(keytab[n].count > 0)
      printf("%4d %s\n", keytab[n].count, keytab[n].word);

  return 0;
 }

  int binsearch(char *word, struct key tab[], int n) {
    int cond;
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
      mid = (low+high)/2;
      if((cond = strcmp(word,tab[mid].word)) < 0)
        high = mid - 1;
      else if (cond > 0)
	low = mid + 1;
      else
	return mid;
    }
    return -1;
  }

  int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w  = word;

    while(isspace(c = getch()))
      ;
    if (c != EOF)
      *w++ = c;
    if(!isalpha(c)) {
      *w = '\0';
      return c;
    }
    for(; --lim > 0; w++)
      if(!isalnum(*w = getch())) {
	ungetch(*w);
	break;
      }
    *w = '\0';
    return word[0];
  }

  
int getch(void){
    if (bufp > 0){
       return buf[--bufp];
    }else{
       return getchar();      
       }
   }
    
void ungetch(int c){ 
  if (bufp >= 50){
    printf("ungetch: too many characters\n");
  }  else{
    buf[bufp++] = c;
    }
}	


