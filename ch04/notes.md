# Chapter 4 - Functions

The reason a mismatch of return types can happen is that if there is no function prototype, a function is implicitly declared by its first appearance in an expression, such as `sum += atof(line)`. If a name that has not been previously declared occurs in an expression and is followed by a left parentheses, it is declared by context to be a function name, the function is assumed to return an `int`, and nothing is assumed about its arguments.

If the function takes arguments, declare them; if it takes no arguments, use `void`.