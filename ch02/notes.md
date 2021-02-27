# Chapter 2 - Types, Operators, and Expressions

- Expressions combine variables and constants to produce new values.
- Use lower case for variable names, and all upper case for symbolic constants.
- Use short names for local variables, especially loop indices, and longer names for external variables.

There are only `int`, `char`, `float` and `double` basic data types and you can apply `long`(at least 32-bits) and `short`(16-bits) to `int` or `double` and word `int`/`double` can even be omitted.

A `character constant` is an integer, written as one character within single quotes, such as `x`. The value of a character constant is the numberic valye of the character in the machine's character set.

Certain characters can be represented in character and string constant by escape sequances like `\n` (newline): this looks like two characters, but represents only one.
char | action |ch | action
---|---|---|---
\a | alert (bell) character | \\\ |backslash
\b | backspace | \\? |question mark
\f | formfeed | \\' |single quote
\n |newline | \\" |double quote
\r |carriage return | \x hh |hexadecimal number
\t |horizontal tab | \v |vertical tab
<br>

The character constant `\0` represents the character with value zero, the `null` character.

library function `strlen(s)` returns the length of its character string argument `s`, excluding the terminal `\0`. The `strlen` and other string functions are declared in the standard header `<string.h>`.

`'x'` is not the same as `"x"`. The former is an integer, used to produce the numeric value of the letter x in the machine's character set. The latter is an array of characters that contains one character (the letter x) and a `'\0'`.

_enumeration constant_ is a list of constant integer values, as in ```enum boolean { NO, YES };```

> The first name in an `enum` has value 0, the next 1, and so on, unless explicit values are specified.

Enumerations provide a convenient way to associate constant values with names, an alternative to `#define` with the advantage that the values can be generated for you.

> Automatic variables for which is no explicit initializer have undefined (i.e., garbage) values.

> The const declarati on can also be used with array arguments, to indicate that the function does not change that array.