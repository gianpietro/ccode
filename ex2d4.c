#include <stdio.h>
#include <string.h>					           // string.h library header

#define MAXLENGTH 100

int main(void) {
  
  char s1[MAXLENGTH];
  char s2[MAXLENGTH];
  char * r;
  int sl1;
  int sl2;
  int i;
  int j;
  int k = 0;

  printf("Enter a string ");
  fgets(s1, MAXLENGTH, stdin);
  printf("Enter characters to find in string ");
  fgets(s2, MAXLENGTH, stdin);

  
  sl1 =  strlen(s1)-1;                                                // string length function  
  printf("string length for s1 %d\n", sl1);
  sl2 = strlen(s2)-1;
  printf("string length for s2 %d\n", sl2);

  for (i=0; i<sl2; ++i){                                           // loop through s2 for each character to search
    for (j=0; j<sl1; ++j){                                         // loop thorugh s1 to seach if character exists  
      if (s1[j] == s2[i] && s2[i] != ' ' && s2[i] != '\n'){        // if char in s2 is not a space and exists in s1
	printf("Character %c is at location %d\n", s1[j], j+1);    // print the char and its location
	k = 2;
      } else if (k != 2){
	k = 1;
      }
    }
  }

  if (k==1){
    printf("No match found\n");
  }
   
  r = strpbrk(s1, s2);                                             // will return first char in s1 which is in s2
  if (r != 0)
    printf("First matching character %c\n", *r);

 return 0;
}
