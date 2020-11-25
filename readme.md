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
* Exercises
    1. Run the "hello, world" program on your system. Experiment with leaving out parts of the program, to see what error messages you get. [possible solution.](chapter1/exercise1-1.c)
    2. Experiment to find out what happens when printf's argument string contains \c, where c is some character not listed above. [possible solution.](chapter1/exercise1-2.c)
    3. Modify the temperature conversion program to print a heading above the table. [possible solution](chapter1/exercise1-3.c)
    4. Write a program to print the corresponding Celsius to Fahrenheit table. [possible solution](chapter1/exercise1-4.c)
    5. Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0. [possible solution](chapter1/exercise1-5.c)
    6. Verify that the expression getchar() != EOF is 0 or 1. [possible solution](chapter1/exercise1-6.c)
    7. Write a program to print the value of EOF.  [possible solution](chapter1/exercise1-7.c)
    8. Write a program to count blanks, tabs, and newlines. [possible solution](chapter1/exercise1-8.c)
    9. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank. [possible solution](chapter1/exercise1-9.c)
    10. Write a program to copy its input to its output, replacing each tab by \t , each backspace by \b , and each backslash by \\ . This makes tabs and backspaces visible in an unambiguous way. [possible solution](chapter1/exercise1-10.c)
    11. How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any? [possible solution](chapter1/exercise1-11.txt)
    12. Write a program that prints its input one word per line. [possible solution](chapter1/exercise1-12.c)
    13. Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging. [possible solution](chapter1/exercise1-13.c)
    14. Write a program to print a histogram of the frequencies of different characters in its input. [possible solution](chapter1/exercise1-14.c)
    15. Rewrite the temperature conversion program of Section 1.2 to use a function for conversion. [possible solution](chapter1/exercise1-15.c)
    16. Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines, and as much as possible of the text. [possible solution](chapter1/exercise1-16.c)
    17. Write a program to print all input lines that are longer than 80 characters. [possible solution](chapter1/exercise1-17.c)
    18. Write a program to remove all trailing blanks and tabs from each line of input, and to delete entirely blank lines. [possible solution](chapter1/exercise1-18.c)
    19. Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time. [possible solution](chapter1/exercise1-19.c)
    20. Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter? [possible solution](chapter1/exercise1-20.c)
    21. Write a program entab that replaces strings of blanks with the minimum number of tabs and blanks to achieve the same spacing. Use the same stops as for detab . When either a tab or a single blank would suffice to reach a tab stop, which should be given preference? [possible solution](chapter1/exercise1-21.c)
    22. Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column. [possible solution](chapter1/exercise1-22.c)
    23. Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C comments do not nest. [possible solution](chapter1/exercise1-23.c)
    24. Write a program to check a C program for rudimentary syntax errors like unbalanced parentheses, brackets and braces. Don't forget about quotes, both single and double, escape sequences, and comments. (This program is hard if you do it in full generality.) [possible solution](chapter1/exercise1-24.c)

## Chapter 2 - Types, Operators, and Expressions
* Constants
    * leading `0` means octal
    * leading `0x` or `0X` means hexadecimal
    * enumeration - first value is 0, then 1, then 2, so on (unless specified)
        * ``enum boolean { NO, YES };`` // NO = 0, YES = 1
        * ``enum suit { HEART =1, DIAMOND, CLUB, SPADE};`` // HEART=1, DIAMOND=2, so on..
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

* Exercises
    1. Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, by printing appropriate values from standard headers and by direct computation. Harder if you compute them: determine the ranges of the various floating-point types. [possible solution](chapter2/exercise2-1.c)
    2. Write a loop equivalent to the for loop above without using && or ||. [possible solution](chapter2/exercise2-2.c)
    3. Write the function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F. [possible solution](chapter2/exercise2-3.c)
    4. Write an alternate version of squeeze(s1,s2) that deletes each character in the string s1 that matches any character in the string s2 . [possible solution](chapter2/exercise2-4.c)
    5. Write the function any(s1,s2) , which returns the first location in the string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2 . (The standard library function strpbrk does the same job but returns a pointer to the location.) [possible solution](chapter2/exercise2-5.c)
    6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged. [possible solution](chapter2/exercise2-6.c)
    7. Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged. [possible solution](chapter2/exercise2-7.c)
    8. Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n bit positions. [possible solution](chapter2/exercise2-8.c)
    9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x . Explain why. Use this observation to write a faster version of bitcount. [possible solution](chapter2/exercise2-9.c)
    10. Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression instead of if-else. [possible solution](chapter2/exercise2-10.c)

## Chapter 3 - Control Flow
