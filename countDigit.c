/* count digits, white space, others */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  #define UPPER 10
  
  int stp;
  int c, i, nwhite, nother;
  int ndigit[UPPER];
  int r, x, y, z, m, k;
  
  i = k = r = x = y = z = m = 0;
  nwhite = nother = 0;
 
  system("COLOR F2");  //https://agyanadda.blogspot.com/2019/01/how-to-color-of-text-in-c-language.html

  for (i = 0; i < UPPER; ++i)
     ndigit[i] = 0;

  /* following code allows for user to enter a series of digits
     and characters until the EOF is reached. 
     To get EOF in Windows press ctrl+Z for Linux press ctrl+D 
  */ 
  while ((c = getchar()) != EOF) 		
    if (c >= '0' && c <= '9')
         ++ndigit[c-'0']; 	 	            // '0' has a value of 48. Sets c = 0 to 9. Index array + 1
  /* ndigit[c-'0'] = ndigit[c-'0'] + 1; */          //  same achieved by
    else if (c == ' ' || c == '\n' || c == '\t')    
      ++nwhite;				            //  count white spaces
    else
      ++nother;                                     //  count any other tyoe of char

  printf("digits =");
  for (i = 0; i < UPPER; ++i)
    printf(" %d", ndigit[i]);
  printf(", white space = %d, other = %d\n",nwhite, nother);     // totals for each char digit, white space and other
 
  printf("\n");
  printf("Vertical Horizontal histogram of digit values between 0 and 9\n");
  printf("------------------------------------------------------\n");
  printf("\n");
    
  for (i=0; i < UPPER; i++){   
      k = ndigit[i];
      for (m=0; m < k; m++){ 
        printf("X");
      }   
      printf("\n");     
    }
 
    printf("\n");
  
    /* find the highest value held in the array */
    for (i=0; i < UPPER; i++){   
       y = ndigit[i];
       if (y > z) {
         z = y;                 // z will hold the highest value
       }
    }
    printf("digits =");
    for (i = 0; i < UPPER; ++i)
      printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n",nwhite, nother);   
    printf("value of largest item %d\n", z);
    printf("\n");
    printf("Horizontal histogram of digit values between 0 and 9\n");
    /*  printf("----------------------------------------------------------------------------\n");
    printf("\n");   
    for (i = 0; i < UPPER; ++i)
       printf("%d\t", i);
       printf("\n----------------------------------------------------------------------------\n"); */
    printf("\n");

    /* The digit which occurs the most is stored in z
       using a loop from z down to zero if the array index
       has a value of z or higher then it will print an astrix.
       The value of z is then reduced by 1. Again the loop starts and
       if the value in the array index is higher or equale z an
       astrix will be printed */

    for (r=z; r > 0; r--){         
      for (i=0; i < UPPER; i++){  
   	if(ndigit[i] >= z)
          printf("X\t");
	else
	  printf(" \t");
      }
       printf("\n");
      z--;
    }    
    printf("----------------------------------------------------------------------------\n");
    printf("\n");   
    for (i = 0; i < UPPER; ++i)
       printf("%d\t", i);
    printf("\n----------------------------------------------------------------------------\n");      
 
  scanf("%d", &stp);

  return 0;
}
