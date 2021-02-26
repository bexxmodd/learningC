
- A text stream is a sequence of characters divided into lines; each line consists of zero or more characters followed by a newline character.

- `getchar()` - reads the next input character from the text stream and returns its value.
- `putchar()` - prints a character each time it is called.

The solution is that getchar returns a distinctive value called EOF, for 'end of file'. We must declare c to be a type big enough to hold any value that getchar returns. We can't use `char` since c must be big enough to hold EOF so we use `int`

`EOF` is an integer defined in <stdio.h>

The precedence of != is higher than that of = , which means that without parentheses  the relational test != would be done before the assignment =.

A character written between single quotes represents an integer value equal to the numerical value of the character in the machine's character set. This is called a _character constant_.

if a input is a digit (which can be checked by `if (c >= '0' && c <= '9')`) its numberic value is `c-'0'`

Since `main` is a function like any other, it may return a value to its caller, which is in effect the environment inwhich the program was executed. Typically, a return value of zero implies normal termination; non-zero values signal unusual or erroneous termination conditions.