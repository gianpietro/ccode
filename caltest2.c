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
  char h;
  int i = 0; 


  while ((type = getop(s)) != EOF){
    switch(type){
    case '0':
      printf("MAIN type = %d\n", type);
      push(atof(s));
      break;
      /* case '+':
      push(pop() + pop());
      break;*/
       case '\n':
	 printf("MAIN case new line \t%.8g\n");//, pop());
      break;
    default:
      printf("MAIN error: unknow command %s\n", s);
      break;
      }
  }
  return 0;
}

void push(double f){
  if (sp < 100){
    // printf("\t \t PUSH##value sp %d\n", sp);
    val[sp++] = f;
    printf("\t \t PUSH##value sp %d\n", sp);
    printf("\t \t PUSH##val[sp] value %f\n", val[--sp]);
    //printf("\t \t PUSH##value sp after increase %d\n", sp);
  }else{
    printf("\t \t PUSH##error: stack full, can't push %g\n", f);
  }
}

/*
double pop(void){
  if (sp > 0)
    return val[--sp];
  else
    printf("error: stack empty\n");
   return 0.0;
}
*/
int getop(char s[]){
  int i, c;
  int j;
  // printf("value of c %d\n", c );
  while ((s[0] = c = getch()) == ' ')
    ;  
  s[1] = '\0';
  // if(!isdigit(c))
  //  return c;
  i = 0;
  if (isdigit(c)){
    while (isdigit(s[++i] = c = getch()))
      printf("GETOP isdigit %d\n",isdigit(s[i] = c = getch()));
      for (j=0; j<i; j++)
	printf("\t GETOP isdigit %d loop value \%d\n",j, s[j]-48);
      // return c;
    }
  // printf("\t GETOP value of i %d\n",i);
  printf("\t GETOP value i%d of s[]* %d\n",i, s[i] );
  s[i] = '\0';
  //if (c != EOF)
  //ungetch(c);
  //buf[bufp++] = c;
  //printf("bufp %d value-%d \n", bufp, buf[bufp]);
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
       return (bufp > 0) ? buf[--bufp] : getchar();
 }
*/

int getch(void){
  if (bufp < 0){
    printf("GETCH***value bufp below zero %d\n", bufp);
    printf("GETCH***value bufp* below zero %d\n", buf[bufp]);
    return getchar();
  }else if (bufp > 0){
      printf("GETCH***value bufp greater zero %d\n", bufp);
      printf("GETCH***value bufp* below zero %d\n", buf[bufp]);
      // printf("buf[--bufp] = %d \n",buf[--bufp]);
      return buf[--bufp];
  }else{
    printf("GETCH***getch is zero \n");
    // printf("GETCH***value bufp* at zero %d\n", buf[bufp]);
    return getchar();
  }
}


/*void ungetch(int c){ 
  if (bufp >= 100)
    printf("ungetch: too many characters\n");
    else
    buf[bufp++] = c;
    }*/
