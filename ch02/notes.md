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

When an opeartor has operands of different types, they are converted to a common type according to following rules:

- In general the only automatic covnersions are for narrow operan into wider without losing information, such as converting an `int` to `float`:
    - expression `f + i`
- `char` is a small integer so they can be used in arithmetic expressions.

The standard header `<ctype.h>` defines a family of functions that provide tests and converions that are independent of character set.

Explicit type conversions can be forced (_coerced_) in any expression, with a unary operator call a `cast`: _(type name) expression_.

```
int n = 49;
sqrt((double) n); // converting n to double as that's what sqrt() expects as argument
```

The expression `++n` increments `n` _before_ its value is used, while `n++` increments `n` _after_ its value has been used.

The _conditional expression_ can be written with the ternary operator `?:` that looks like this: `expr1 ? expr2 : expr3`. The expression `expr1` is evaluated first. If it is true, then the expression `expr2` is evaluated, and that is a value of the conditional expression. Otherwise `expr3` is evaluated, and that is the value. Example:

```
z = (a > b) ? a : b; // z = max(a, b)
```
