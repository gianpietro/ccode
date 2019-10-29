/* C Programming Language Ex 1-3
   Modify the temperature cobversion program to print
   a heading avove the table.
*/

#include <stdio.h>

int main(void) {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0; 					// lower limit of temperature table
  upper = 300;					// upper limit
  step = 20;					// step size

  fahr = lower;
  printf("Fahrenheit\t Celsius\n");		// using \t for tab
  while (fahr <= upper) {
    celsius = (5.0/9.0) * (fahr - 32.0);
    printf("%3.0f\t\t %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
  
  return 0;
}
