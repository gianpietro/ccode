/* This program is a modification of the countKeyword.c program
which now uses pointers

This example uses a structure to store a list of keywords
and the struct has a count value to store the number of times
that keyword is entered into the terminal. 
The user types words in and the program counts
any keywords which are found in the structure. The for loop statement
uses pointer aritmatic to go through each item in the keytab structure. 
keytab[].count is updated for that word by 1 each time the word is entered. 
The word and count (total)is displayed when EOF reached. */

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
//UPDATE function binsearch returning a struct key * (pointer)
struct key *binsearch(char *, struct key *, int);

int getch(void);
void ungetch(int);
char buf[10];
int bufp = 0;

int main ()
{

  char word[MAXWORD];

  //UPDATE
  struct key *p;

  while (getword(word,MAXWORD) != EOF)
    if (isalpha(word[0]))
      //UPDATE ptr version
      if ((p = binsearch(word,keytab,NKEYS)) != NULL)	
	p->count++;  
  /* the for loop uses pointer aritmatic to loop through each item
     of the structure. It starts at keytab[0] and number of items
     in struct is NKEYS.
     It then moves to next item with p++ so keytab[1] and so on
  */
  for(p = keytab; p < keytab + NKEYS; p++)
    if (p->count > 0) 
      printf("%4d %s", p->count, p->word);    

  return 0;
 }


//UPDATE ptr version
struct key *binsearch(char *word, struct key *tab, int n) {
  int cond;
  struct key *low = &tab[0];
  struct key *high = &tab[n];
  struct key *mid;

  while (low < high) {
    mid = low + (high-low) / 2;
    if ((cond = strcmp(word, mid->word)) < 0)
      high = mid;
    else if (cond > 0)
      low = mid + 1;
    else
      return mid;
  }
  return NULL;
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


