
- A text stream is a sequence of characters divided into lines; each line consists of zero or more characters followed by a newline character.

- `getchar()` - reads the next input character from the text stream and returns its value.
- `putchar()` - prints a character each time it is called.

The solution is that getchar returns a distinctive value called EOF, for 'end of file'. We must declare c to be a type big enough to hold any value that getchar returns. We can't use `char` since c must be big enough to hold EOF so we use `int`

`EOF` is an integer defined in <stdio.h>

The precedence of != is higher than that of = , which means that without parentheses  the relational test != would be done before the assignment =.

A character written between single quotes represents an integer value equal to the numerical value of the character in the machine's character set. This is called a _character constant_.

if a input is a digit (which can be checked by `if (c >= '0' && c <= '9')`) its numberic value is `c-'0'`

Since `main` is a function like any other, it may return a value to its caller, which is in effect the environment inwhich the program was executed. Typically, a return value of zero implies normal termination; non-zero values signal unusual or erroneous termination conditions.

in C all function arguments are passed _by value_. This means that the called function is given the values of its arguments in temporary variables rather than the originals.

When argument is passed to the function, whatever is done to that argument inside the function has no effect of the arguments that function was originally called with.

It is possible to arrange for a function to modify a variable in a calling routine.

However, there is no copying of array elements. By subscripting this value, the function can access and alter any arguments of the array.

String is stored as an array of characters containing the characters in the string and terminated with a `\0` to mark the end.

A common practice is to place definitions of all external variables at the beginning of the source file, and then omit all extern declarations.

If the program is in several source files, and a variable is defined in _file1_ and used in _file2_ and _file3_, then extern declarations are needed in _file2_ and _file3_ to connect the occurrences of the variable. The usual practice is to collect extern declarations of variables and functions in a separate file, historically called a header, that is included by `#include` at the front of each source file. The suffix `.h` is conventional for header names.

