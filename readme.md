# The C programming language (2nd edition) 

## Goal summary
* Develop a fundamental understanding of the C language, a precursor to many [languages](https://en.wikipedia.org/wiki/List_of_C-family_programming_languages) and [uses](https://en.wikipedia.org/wiki/C_%28programming_language%29#Uses).

## Chapter 1 - A tutorial Introduction
* Function arguments are pass by value. Exceptions:
    * Arrays are passed by reference
    * Sending the memory location will pass by reference
* Variables called within a function are local/private to that function (aka automatic variables). Exceptions:
    * `static` (ch4)
    * `external` - globally accessible, defined outside a function, remains in existence permanently and value is editable. To use in function, name must be made known with `extern` declaration prior to the type.
* [ASCII chars](http://www.asciitable.com/) via single quotes: ``int val = 'A';`` val is 65
* Convert int to string ``char two = 2 + '0';``
### Chapter 1 exercises:

1. *Run the "hello, world" program on your system. Experiment with leaving out parts of the program, to see what error messages you get.* [possible solution.](chapter1/exercise1-1.c)

1. *Experiment to find out what happens when printf's argument string contains \c, where c is some character not listed above.* [possible solution.](chapter1/exercise1-2.c)

1. *Modify the temperature conversion program to print a heading above the table.* [possible solution](chapter1/exercise1-3.c)

1. *Write a program to print the corresponding Celsius to Fahrenheit table.* [possible solution](chapter1/exercise1-4.c)

1. *Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.* [possible solution](chapter1/exercise1-5.c)

1. *Verify that the expression getchar() != EOF is 0 or 1.* [possible solution](chapter1/exercise1-6.c)

1. *Write a program to print the value of EOF.* [possible solution](chapter1/exercise1-7.c)

1. *Write a program to count blanks, tabs, and newlines.* [possible solution](chapter1/exercise1-8.c)

1. *Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.* [possible solution](chapter1/exercise1-9.c)

1. *Write a program to copy its input to its output, replacing each tab by \t , each backspace by \b , and each backslash by \\ . This makes tabs and backspaces visible in an unambiguous way.* [possible solution](chapter1/exercise1-10.c)

1. *How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?* [possible solution](chapter1/exercise1-11.txt)
1. *Write a program that prints its input one word per line.* [possible solution](chapter1/exercise1-12.c)

1. *Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.* [possible solution](chapter1/exercise1-13.c)

1. *Write a program to print a histogram of the frequencies of different characters in its input.* [possible solution](chapter1/exercise1-14.c)

1. *Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.* [possible solution](chapter1/exercise1-15.c)

1. *Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines, and as much as possible of the text.* [possible solution](chapter1/exercise1-16.c)

1. *Write a program to print all input lines that are longer than 80 characters.* [possible solution](chapter1/exercise1-17.c)

1. *Write a program to remove all trailing blanks and tabs from each line of input, and to delete entirely blank lines.* [possible solution](chapter1/exercise1-18.c)

1. *Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.* [possible solution](chapter1/exercise1-19.c)

1. *Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?* [possible solution](chapter1/exercise1-20.c
)
1. *Write a program entab that replaces strings of blanks with the minimum number of tabs and blanks to achieve the same spacing. Use the same stops as for detab . When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?* [possible solution](chapter1/exercise1-21.c)

1. *Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.* [possible solution](chapter1/exercise1-22.c)

1. *Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C comments do not nest.* [possible solution](chapter1/exercise1-23.c)

1. *Write a program to check a C program for rudimentary syntax errors like unbalanced parentheses, brackets and braces. Don't forget about quotes, both single and double, escape sequences, and comments. (This program is hard if you do it in full generality.)* [possible solution](chapter1/exercise1-24.c)


## Chapter 2 - Types, Operators, and Expressions
* Constants
    * leading `0` means octal
    * leading `0x` or `0X` means hexadecimal
    * enumeration - first value is 0, then 1. *then 2, so on (unless specified)
        * ``enum boolean { NO, YES };`` // NO = 0, YES = 1
        * ``enum suit { HEART =1. *DIAMOND, CLUB, SPADE};`` // HEART=1. *DIAMOND=2, so on..
* Type conversions
    * Automatic conversions only convert "narrower" type to "wider" type
        * int * float = float
    * Explicit type conversion (aka cast)
        * *(type-name) expression*
* Bitwise operators
    * getting desired bits use ``~0`` to get all 1's, then shift as needed (adding zeros) then take complement of that:
        * ``value & ~(~0 << n)`` // gives `n` right bits of `value`

| Oper  | Meaning  |
| :---- | :------- |
| & | AND |
| \| | OR |
| ^ | XOR |
| << | left-shift |
| >> | right-shift |
| ~ | 1's complement |

### Chapter 2 exercises:

1. *Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, by printing appropriate values from standard headers and by direct computation. Harder if you compute them: determine the ranges of the various floating-point types.* [possible solution](chapter2/exercise2-1.c)

1. *Write a loop equivalent to the for loop above without using && or ||.* [possible solution](chapter2/exercise2-2.c)

1. *Write the function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.* [possible solution](chapter2/exercise2-3.c)

1. *Write an alternate version of squeeze(s1,s2) that deletes each character in the string s1 that matches any character in the string s2 .* [possible solution](chapter2/exercise2-4.c)

1. *Write the function any(s1,s2) , which returns the first location in the string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2 . (The standard library function strpbrk does the same job but returns a pointer to the location.)* [possible solution](chapter2/exercise2-5.c)

1. *Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.* [possible solution](chapter2/exercise2-6.c)

1. *Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.* [possible solution](chapter2/exercise2-7.c)

1. *Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n bit positions.* [possible solution](chapter2/exercise2-8.c)

1. *In a two's complement number system, x &= (x-1. *deletes the rightmost 1-bit in x . Explain why. Use this observation to write a faster version of bitcount.* [possible solution](chapter2/exercise2-9.c)

1. *Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression instead of if-else.* [possible solution](chapter2/exercise2-10.c)

## Chapter 3 - Control Flow
 * `break;` takes you out of the innermost loop or switch
 * [Shell sort](chapter3/shellsort.c) (in-place)
    * Utilizing 2 pointers to create a gap, the algo starts with a gap of half the size of the array. It works it's way from left to right in the array testing if the right pointer is less than the left pointer (switching elements if true). When it reaches the end of the array the gap is halved and cycle repeats til gap is 1.

### Chapter 3 exercises:

1. *Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside). Write a version with only one test inside the loop and measure the difference in run-time.* [possible solution](chapter3/exercise3-1.c)
1. *Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s . Use a switch . Write a function for the other direction as well, converting escape sequences into the real characters.* [possible solution](chapter3/exercise3-2.c)
1. *Write a function expand(s1,s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2 . Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z . Arrange that a leading or trailing - is taken literally.* [possible solution](chapter3/exercise3-3.c)
1. *In a two's complement number representation, our version of itoa does not handle the largest negative number, that is, the value of n equal to -(2 to the power (wordsize - 1)) . Explain why not. Modify it to print that value correctly regardless of the machine on which it runs.* [possible solution](chapter3/exercise3-4.c)
1. *Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s . In particular, itob(n,s,16) formats n as a hexadecimal integer in s .* [possible solution](chapter3/exercise3-5.c)
1. *Write a version of itoa that accepts three arguments instead of two. The third argument is a minimum field width; the converted number must be padded with blanks on the left if necessary to make it wide enough.* [possible solution](chapter3/exercise3-6.c)

## Chapter 4 - Functions and Program Structure

* Function structure:

```none
return-type function-name(argument declarations)
{
    declarations and statements
}
```

* Reverse polish notation (RPN) - operator follows the operands
    * `(1-2) * (4+5)` becomes `1 2 - 4 5 + *`
    * utilizes a stack
    * [base RPN calculator](chapter4/reversePolishCalculator.c) that exercises build on
* Functions cannot be defined inside other functions
* Header files can be used to modularize and organize the program
* `static` variables are for private use of functions in the respective source file(s)
    * `static` can be applied to variables **and** functions
* [Quicksort algorithm](chapter4/qsort.c)
* C preprocessor handles the `#include...` and `#define...` tags
* Macro substitution
    * simplest form is direct replacement `#define name replacement text`
    * can take arguments and create replacement text 
    ```c
    #define dprint(expr) printf(#expr " = %g\n", expr)

    dprint(x/y); //becomes:

    printf("x/y = %g\n", x/y);
    ```
    * `#` operator takes `expr` as a string
    * `##` operator catenates arguments and trims whitespace
    * `\` allows for multiline macros (aka to-be-continued)
    * conditional macros are possible too
    ```c
    #if SYSTEM == SYSV
        #define HDR "sysv.h"
    #elif SYSTEM == BSD
        #define HDR "bsd.h"
    ...
    #else
        #define HDR "default.h"
    #endif
    #include HDR
    ```

### Chapter 4 exercises:
1. Write the function strrindex(s,t), which returns the position of the rightmost occurrence of t in s, or -1 if there is none. [possible solution](chapter4/exercise4-1.c)
1. Extend atof to handle scientific notation of the form 123.45e-6 where a floating-point number may be followed by e or E and an optionally signed exponent. [possible solution](chapter4/exercise4-2.c)
1. Given the basic framework, it's straightforward to extend the calculator. Add the modulus ( % ) operator and provisions for negative numbers. [possible solution](chapter4/exercise4-3.c)
1. Add commands to print the top element of the stack without popping, to duplicate it, and to swap the top two elements. Add a command to clear the stack. [possible solution](chapter4/exercise4-4.c)
1. Add access to library functions like sin, exp, and pow . See <math.h> in Appendix B, Section 4. [possible solution](chapter4/exercise4-5.c)
1. Add commands for handling variables. (It's easy to provide twenty-six variables with single-letter names.) Add a variable for the most recently printed value. [possible solution](chapter4/exercise4-6.c)
1. Write a routine ungets(s) that will push back an entire string onto the input. Should ungets know about buf and bufp , or should it just use ungetch? [possible solution](chapter4/exercise4-7.c)
1. Suppose there will never be more than one character of pushback. Modify getch and ungetch accordingly. [possible solution](chapter4/exercise4-8.c)
1. Our getch and ungetch do not handle a pushed-back EOF correctly. Decide what their properties ought to be if an EOF is pushed back, then implement your design. [possible solution](chapter4/exercise4-9.c)
1. An alternate organization uses getline to read an entire input line; this makes getch and ungetch unnecessary. Revise the calculator to use this approach. [possible solution](chapter4/exercise4-10.c)
1. Modify getop so that it doesn't need to use ungetch. Hint: use an internal static variable. [possible solution](chapter4/exercise4-11.c)
1. Adapt the ideas of printd to write a recursive version of itoa ; that is, convert an integer into a string by calling a recursive routine. [possible solution](chapter4/exercise4-12.c)
1. Write a recursive version of the function reverse(s) , which reverses the string s in place. [possible solution](chapter4/exercise4-13.c)
1. Define a macro swap(t,x,y) that interchanges two arguments of type t . (Block structure will help.) [possible solution](chapter4/exercise4-14.c)

## Chapter 5 - Pointers and Arrays

* Pointers point to a specific memory address
    * `&` gives address of an object
    * `*` dereferences/indirection of pointer (aka gives the value of whatever the pointer is pointing at)
    * pointers have a type, but generic is possible with `void *`

### Chapter 5 exercises:
1. As written, getint treats a + or - not followed by a digit as a valid representation of zero. Fix it to push such a character back on the input. [possible solution](chapter5/exercise5-1.c)
1. Write getfloat , the floating-point analog of getint . What type does getfloat return as its function value? [possible solution](chapter5/exercise5-2.c)
