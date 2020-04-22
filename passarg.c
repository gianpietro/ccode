/*****************************************
pass arguments into a program - change program behaviour
depending on the argv passed in at run time.

This has been adapted to that if the second argument entered when program 
is run is the string lower, user then enters a value in upper case and it is 
converted to lower case.If argument is string upper then a lower case value is
converted to upper case. At prompt enter program name and argument:-
/passarg lower 
or
/passarg upper

note how strcmp is used to identify the argv value passed in.

****************************************/
// passarg.c

#include <stdio.h>
#include <string.h>
#include <ctype.h>                               /* used for functions tolower() toupper() */

int main(int argc, char *argv[]) {
  int i;
  int c;
 
  printf("I have %d arguments from the command line: \n", argc);
  /* for (i; i<argc; i++) {
   printf("Argument %d: %s\n", i, argv[i]);
  }
  */

  if (strcmp(argv[1], "lower") == 0) {           /* argument at prompt equals lower */
    printf("%s\n",argv[1]);                      /* print argument */    
    while ((c = getchar()) != '9')               /* enter uppercase string, enter 9 to exit */
      putchar(tolower(c));                       /* convert string to lowercase */    
  } else if (strcmp(argv[1], "upper") == 0){     /* argument at prompt equals upper */
      printf("%s\n",argv[1]);                    /* print argument */
      while ((c = getchar()) != '9') 	         /* enterlowercase string, enter 9 to exit */
        putchar(toupper(c));                     /* convert string to uppercase */    
  }
  
  while (c != '9')                               /* while char does not equal 9 */
    printf("%c", c);                             /* print converted string */
  
  
  return 0;
}
