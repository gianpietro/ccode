#include <stdio.h>

int main(void)
{
  int i, j, k, c;
  char s[15];
  
  for (i=0; i < 15 && (c = getchar()) != EOF && c != '\n'; ++i) 
      s[i] = c;
       if (c == '\n'){
         printf("string before LF: %s\n",s);
         s[i] = c;
       ++i;    
       }
       s[i] = '\0';
 
       //return i;
     
   for (k=0; k < 15; ++k){
      printf("array k %d value %c\n", k, s[k]); 
   }

    for (k=0; k < 15; ++k){
      printf("%c",s[k]); 
   }
      return 0;
}
