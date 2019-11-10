/* count digits, white space, others */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  #define UPPER 10
  #define ANSI_COLOR_RED "\x1b[5;33m"
  #define ANSI_COLOR_RESET "\x1b[0m"
  
  int stp;
  int c, i, nwhite, nother;
  int ndigit[UPPER];
  int r, x, y, z, m, k;
  
  i = k = r = x = y = z = m = 0;
  nwhite = nother = 0;
 
  //system("color 9F");  //https://agyanadda.blogspot.com/2019/01/how-to-color-of-text-in-c-language.html

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
  printf("Horizontal histogram of digit values between 0 and 9\n");
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
         z = y;                                             // z will hold the highest value
       }
    }
    printf("digits =");
    for (i = 0; i < UPPER; ++i)
      printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n",nwhite, nother);   
    printf("value of largest item %d\n", z);
    printf("\n");
    printf("Vertical histogram of digit values between 0 and 9\n");
    printf("\n");

    for (r=z; r > 0; r--){                                  // start a loop with the highest occurring value, z
      for (i=0; i < UPPER; i++){                            // loop through the array
   	if(ndigit[i] >= z)                                  // if the value of array is >= highest occurring value
          printf(ANSI_COLOR_RED "X\t" ANSI_COLOR_RESET);    // print the character X  
	else
	  printf(" \t");                                    // otherwise move a space along
      }
       printf("\n");
       z--;                                                 // reduce the value of z by 1
    }    
    printf("----------------------------------------------------------------------------\n");
    printf("\n");   
    for (i = 0; i < UPPER; ++i)
       printf("%d\t", i);
    printf("\n----------------------------------------------------------------------------\n");      


    printf("\033[5;32mGraph of digits entered!\n" ANSI_COLOR_RESET);         // print text in red
  scanf("%d", &stp);

  return 0;
}
