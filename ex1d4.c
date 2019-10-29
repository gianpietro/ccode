/* C Programming Language Ex 1-4
   Write a program to print the corresponding Celsius to 
   Fahrenheit table
*/

#include <stdio.h>

int main(void) {
  float fahr, celsius;
  int lower, upper, step;

  // SYMBOLIC CONSTANTS   
  #define LOWER 0				// lower limit of temperature table
  #define UPPER 100                             // upper limit
  #define STEP 5				// step size

  celsius = LOWER;
  printf("Celsius\t\t Farhenheit\n");		// using \t for tab
  while (celsius <= UPPER) {
    fahr = (9.0/5.0)*celsius + 32.0;
    printf("%3.1f\t\t %6.1f\n", celsius, fahr);
    celsius = celsius + STEP;
  }
 
  return 0;
}
