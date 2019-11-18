#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getop (char []);
void push(double);
double pop(void);

int sp = 0;
double val[100];
int e;

int getch(void);
void ungetch(int);

char buf[100];
int bufp = 0;

int main(void){
  int type;
  double op2;
  char s[100];

  while ((type = getop(s)) != EOF){
    ;
   switch(type){
    case '0':
      //printf("type = %d\n", type);
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
       case '\n':
      printf("case new line \t%.8g\n", pop());
      break;
    default:
      printf("error: unknow command %s\n", s);
      break;
      }
  }
  return 0;
}

void push(double f){
  if (sp < 100)
    val[sp++] = f;
 else
    printf("error: stack full, can't push %g\n", f);
}

double pop(void){
  if (sp > 0)
    return val[--sp];
  else
    printf("error: stack empty\n");
   return 0.0;
}

int getop(char s[]){
  int i, c;

  while ((s[0] = c = getch()) == ' ')
    ;  // printf("value of c %c\n", c);
  s[1] = '\0';
  if(!isdigit(c))
    return c;
  i = 0;
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
     ;
  s[i] = '\0';
  if (c != EOF)
  //ungetch(c);
  buf[bufp++] = c;
  printf("bufp %d value-%d \n", bufp, buf[bufp]);
  return '0';
}
/*
int getch(void){
  if (bufp > 0){
     printf("buf[--bufp] = %d \n",buf[--bufp]);
      return buf[--bufp];
    }else{
      return getchar();      
    }
      // return (bufp > 0) ? buf[--bufp] : getchar();
 }
*/

int getch(void){
  if (bufp < 0){
    printf("value bufp below zero %d\n", bufp);
    printf("value bufp* below zero %d\n", buf[bufp]);
    return getchar();
  }else if (bufp > 0){
      printf("value bufp greater zero %d\n", bufp);
      printf("value bufp* below zero %d\n", buf[bufp]);
      // printf("buf[--bufp] = %d \n",buf[--bufp]);
      return buf[--bufp];
  }else{
    printf("getch is zero \n");
    return getchar();
  }
}


/*void ungetch(int c){ 
  if (bufp >= 100)
    printf("ungetch: too many characters\n");
    else
    buf[bufp++] = c;
    }*/
