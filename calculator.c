#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'

#define MAXVAL 100
#define BUFSIZE 100

int getop (char []);
void push(double);
double pop(void);

int sp = 0;
double val[MAXVAL];
int e;


int getch(void);
void ungetch(int);

char buf[BUFSIZE];
int bufp = 0;

int main(void){
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF){
    switch(type){
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: zero divisor\n");
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknow command %s\n", s);
      break;
    }
  }
  return 0;
}

void push(double f){
  if (sp < MAXVAL){
      printf("sp_push %d\n", sp);
    val[sp++] = f;
  printf("f %f\n", f);
  //printf("sp_pushed %d\n", sp);
  
  }else{
    printf("error: stack full, can't push %g\n", f);
  }
}

double pop(void){
  if (sp > 0){
    printf("&&&& %d\n",sp);
    return val[--sp];
  }else{
    printf("error: stack empty\n");
  }

  return 0.0;
}

int getop(char s[]){
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if(!isdigit(c) && c != '.')
    return c;
  i = 0;
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
    if (c != EOF)
    ungetch(c);
        
  return NUMBER;
}

int getch(void){
  //return (bufp > 0) ? buf[--bufp] : getchar();
  return getchar();
}

void ungetch(int c){
  int i, j;
  j=0;
  //  if (bufp >= BUFSIZE)
  //  printf("ungetch: too many characters\n");
  //  else
    buf[bufp++] = c;
    j++;
    for (i=0;i<j;i++){
      printf("c = %d\n",bufp);
    }
 }
  












