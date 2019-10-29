/* count digits, white space, others */

#include <stdio.h>

int main(void)
{
  int stp;
  int c, i, nwhite, nother;
  int ndigit[10];
  int j, k, m;

  nwhite = nother = 0;
 
   for (i = 0; i < 10; ++i)
     ndigit[i] = 0;

  while ((c = getchar()) != EOF) 		// EOF in Windows ** ctrl + Z + Enter **     in Linux ** ctrl + D **
    if (c >= '0' && c <= '9')
         ++ndigit[c-'0']; 	 		// '0' has a value of 48 so this sets values from 0 to 9 and adds 1 to array index value
  // ndigit[c-'0'] = ndigit[c-'0'] + 1;         // this line is the full expression of the line above and so gives same result
    else if (c == ' ' || c == '\n' || c == '\t')
      ++nwhite;
    else
      ++nother;


  printf("digits =");

  for (i = 0; i < 10; ++i)
    printf(" %d", ndigit[i]);

  printf(", white space = %d, other = %d\n",nwhite, nother);

  //  for (j=0; j<10; j++){
    k = ndigit[1];
    for (m=0; m <k; m++){
      printf("*\n");
    }
    //x  }

  scanf("%d", &stp);

  return 0;

}
