/*  The C programming Language 
    Chapter 2

Value of integer can be specified in o          ctal or hexadecimal

e.g. int 31  as decimal value
     octal value 037  - requires leading 0
     hex value  0x1f  - requires leading 0x / 0X 
        also as 0X1F                 

character constant is an integer written as one character
  e.g '0' has ASCII value 48

string
 the internal representation of a string has a null '\0' character as the end.
 strlen(s) can be used to find length of string
 declared in header <string.h>


difference between 'x' and "x"
character constant 'x' this is an integer used to produce numberic value of the letter 
string "x" - arracy of characters

enumeration constant
  enum boolean {NO, YES}   
  the first name in the enum has the value 0, and the next 1, and so on, 
  unless explicit values specified

  enum months {JAN = 1, FEB, MAR, APR, MAY, JUN,
               JUL, AUG, SEP, OCT, NOV, DEC }
  FEB = 2, MAR = 3  and so on.

 
The qualifier const
  can be applied to the declaration of any variable to specify
  that its value will not be changed
  
  const double e = 2.71828182845905;
  const char msg[] = "warning";

The standard header <ctype.h> is a family of functions that test and provide conversions
  atoi(s) - converts s to integer
  lower(c) - uppercase to lowercase
  isdigit(c)
  


*/

