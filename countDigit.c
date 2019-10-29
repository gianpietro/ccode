/* count digits, white space, others */

#include <stdio.h>

int main(void)
{
  int stp;
  int c, i, nwhite, nother;
  int ndigit[10];
  int j, k, m;
  int x, y, z;
  int p, q, r;
  m = 0;
  j = 0;
  

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
 
  /* histogram with verical bars*/
    for (j=0; j<10; j++){
      k = ndigit[j];
      for (m=0; m <k; m++){ 
         printf("*");
      }   
      printf("\n");     
    }
  
    /* Find the array index with the largest value
       then start a loop from that value and go through 
       array, if the array index is that value print else
       move once space along and check next array value.
       When have completed loop start loop again with the start
       value at largest array value less 1
    */


    y = 0;
    z = 0;
    r =0;

    for (x=0; x<10; x++){
       y = ndigit[x];
       if (y > z) {
         z = y;
       }
    }
    printf("value of largest item %d\n", z);
    
   for(q=0; q<10; q++){
    for (r=z; r>0; r--){   
	if(ndigit[q] == r){  
           printf("*");          
	} else printf(" ");
    }
	   
      }
    }
      


       
 
  scanf("%d", &stp);

  return 0;

}
