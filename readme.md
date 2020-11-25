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
* [Exercises answers](chapter1/)

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

* [Exercise answers](chapter2/)

## Chapter 3 - Control Flow
