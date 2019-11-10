/* Enter a character in upper case and program will convert
to lower case.It uses an if statement to do this and the
later in program it uses a conditional expression to do
the same task
*/


#include <stdio.h>

int main(void){

  char c;
  char z;

  printf("Enter a character in uppercase ");
  scanf("%c", &c);

  printf("You entered %c \n", c);

  if (c >='A' && c <= 'Z') {
    z = c + 'a' - 'A';
    printf("The lowercase letter is %c \n", z);
  }else{
      printf("This was not converted %c \n", c);
  }

  printf("\nUsing conditional expression to convert from upper to lower case\n");

  z = (c >='A' && c <= 'Z') ? c + 'a' - 'A' : c;
  printf("Using conditional expression the lower case char is %c\n", z);

  // this is the final version using a conditional expression
  printf("\nConditional expression with correct printout\n");

  z = (c >='A' && c <= 'Z')
    ?
    printf("Converted to lower case %c\n", c + 'a' - 'A')
    :
    printf("Not converted %c\n",c);
  

  return 0;
}
