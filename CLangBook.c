******************************************
******  The C programming Language *******
******************************************

Chapter 2
=========================

Value of integer can be specified in octal or hexadecimal

e.g. int 31  as decimal value
     octal value 037  - requires leading 0
     hex value  0x1f  - requires leading 0x / 0X 
        also as 0X1F                 

character constant is an integer written as one character
  e.g '0' has ASCII value 48

string
-----------
 the internal representation of a string has a null '\0' character as the end.
 strlen(s) can be used to find length of string
 declared in header <string.h>


difference between 'x' and "x"
character constant 'x' this is an integer used to produce numberic value of the letter 
string "x" - arracy of characters

enumeration constant
-------------------------
  enum boolean {NO, YES}   
  the first name in the enum has the value 0, and the next 1, and so on, 
  unless explicit values specified

  enum months {JAN = 1, FEB, MAR, APR, MAY, JUN,
               JUL, AUG, SEP, OCT, NOV, DEC }
  FEB = 2, MAR = 3  and so on.

 
The qualifier const
-----------------------
  can be applied to the declaration of any variable to specify
  that its value will not be changed
  
  const double e = 2.71828182845905;
  const char msg[] = "warning";

The standard header <ctype.h> is a family of functions that test and provide conversions
  atoi(s) - converts s to integer
  lower(c) - uppercase to lowercase
  isdigit(c)
  
assignment operator
----------------------
  +=    this is the assignmet operator
  i += 2 
 
  expr1 = (expr1) op (expr2)
  except that expr1 is computer only once
  x *= y + 1
  means x = x * (y + 1)
  rather than x = x * y + 1

conditional expressions
---------------------------
  if (a > b)
    z = a
  else
    z = b

the conditional expression written with the ternary operator ?:
provides an alternative way to write this

  expr1 ? expr2 : expr 3

the expression expr1 is evaluated first if it is non-zero (true) the express
expr2 is evaluated and that is the value of the conditional expression
otherwise expr3 is evaluated and that is the value

z = (a > b) ? a : b  // z = max(a,b) //

if expr2 and expr3 are of different typew the result is determined
by the conversion rules (page 44) 

typecast functions
------------------------
Typecast function 	Description
atof() 	Converts string to float
atoi() 	Converts string to int
atol() 	Converts string to long
itoa() 	Converts int to string
ltoa() 	Converts long to string


Chapter 4
=========================

Macros

It is possible to define multi line  macros  using \ 

#define swap(t,x,y) { t = _z; \
	              _z = y; \
                       y = x; \
                       x = _z; }
use braces to define a new block and local variable _z is used


Chapter 5 Pointers and Arrays
=============================

define an array
   int a[10];

define a pointer
   int *pa

then the assignment - set pa to point to selement zero of a
   pa = &a[0];

can also write this as
  pa = a
as name of array is a synonym for the location of the initial element


now the assignment
  x = *pa
copies content of a[0] to x


Pointer Summary
*******************************

int a[10];
int *pa;

pa = &a[0];			// set pa to point to element zero of a, pa contains address of a[0]
 or
pa = a                          // this is the same thing as array name is a synonym 
                                // for the locaton of initial element

x = *pa                         // will copy content of a[0] into x

pa + 1                          // points to next element of array

*(pa + 1)                       // point to contents of element e.g. a[1]  

pa + 1                          // the address of a[1]

pa[i]                           // the same as *(pa + 1)

*(a + 1)                        // the same as a[i]

&a[i] same as a+i               // address of element


static variables
*******************************

1. A static variable inside a function keeps its value between invocations.
2. A static global variable or a function is "seen" only in the file it's declared in

example of case 1.
-------------------

include <stdio.h>

void foo()
{
    int a = 10;
    static int sa = 10;

    a += 5;
    sa += 5;

    printf("a = %d, sa = %d\n", a, sa);
}


int main()
{
    int i;

    for (i = 0; i < 10; ++i)
        foo();
}
                                                                                                                                                        
output:       

a = 15, sa = 15
a = 15, sa = 20
a = 15, sa = 25
a = 15, sa = 30
a = 15, sa = 35
a = 15, sa = 40
a = 15, sa = 45
a = 15, sa = 50
a = 15, sa = 55
a = 15, sa = 60


Pointer functions
**********************
  
int *f();       /* function f returning an int*                        */
int (*g)();     /* pointer g to a function returning an int            */


* is a prefix operator and has lower precedence than ()
so parentheses are used to force the proper association

  
Chapter 6
============

self-referential structures

looking at the binary tree p.139

struct tnode {             /* the tree node  */
  char *word;              /* points to the text */
   int count;              /* number of occurrences */
   struct tnode *left;     /* left child */
   struct tnode *right     /* right child */
   };

It is illegal for a structure to contain an instance of itself, bu
  struct tnode *left;
declares left to be a pomiter to a tnode, not a tnode itself.


Two structures that point to each other

struct t {
   ...
   struct s *p   /*  p points to an s  */
};

struct s {
   ...
   struct t *q   /*  q points to an t  */
};



  
