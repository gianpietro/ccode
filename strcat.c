/* concantenate two strings, enter first string
then enter a scond string and the will concantenate
to the end of the first string 
The second example is using pointers to do strcat
*/

#include <stdio.h>

int main(void) {
  /*char s[20], t[20];
  int i, j;
  
  printf("Enter a word ");
  scanf("%s",s);
  printf("Word to concatenate ");
  scanf("%s",t); 
  
  printf("Word entered %s\n", s);
  printf("Word to concatenate %s\n", t);
   
  i = j = 0;

  while(s[i] != '\0')
    i++;
  while ((s[i++] = t[j++]) != '\0')
    ;
  
  printf("Word entered %s\n", s);
  */
 
  char s[10], t[10];
  char *x, *y;

  printf("Enter a word ");
  scanf("%s",s);
  printf("Word to concatenate ");
  scanf("%s",t);

  x = s;
  y = t;

   while (*x != '\0')
      *x++;                            // *x++ incements the pointer itself
                                       // while *x = *x + 1 increments the value pointed to by pointer                                              // reason not the same 
  
   //*x++ = ' ';                         // put space between two workds
   while ((*x++ = *y++) != '\0')
     ;
   
   printf("Word entered %s\n", s);
  
   return 0;
}
