# Chapter 4 - Functions

The reason a mismatch of return types can happen is that if there is no function prototype, a function is implicitly declared by its first appearance in an expression, such as `sum += atof(line)`. If a name that has not been previously declared occurs in an expression and is followed by a left parentheses, it is declared by context to be a function name, the function is assumed to return an `int`, and nothing is assumed about its arguments.

If the function takes arguments, declare them; if it takes no arguments, use `void`.

External variables are defined outside of any function, and are thus potentionally available to many functions. Functions themselves are always external, because C does not allow functions to be defined inside other functions.

The _scope_ of a name is the part of the program within which the name can be used. The scope of an external variable or a function lasts from the point at which it is declared to the end of the file being compiled.

if an external variable is to be referred to before it is defined, or if it is defined in a different source file from the one where it is being used, then an `extern` declaration is mandatory.

- A _declaration_ announces the properties of a variable (primarily its type); a _definition_ also causes storage to be set aside.

```
int sp;
double val[MAXVAL];
```

If these lines appear outside of any function, they define the external variables `sp` and `val`, cause storage to be set aside, and serve as the declarations for the rest of that source file.

```
extern int sp;
extern double val[];
```

This lines declare for the rest of the source file that `sp` is an `int` and that `val` is a `double` array (whose size is determined elsewhere), but they do not create the varibles or reserve storage for them.

There must be only one definition of an external variable among all the files that make up the source program; other files may contain extern declarations to access it. Initialization of an external variable goes only with the definition.


### Static Variables

- The `static` declaration, applied to an external variable or function, limits the scope of that object to the rest of the source file being compiled.
- If a function is declared static , however, its name is invisible outside of the file in which it is declared.
- internal static variables provide private, permanent storage within a single function.

### Register Variables

- A `register` declaration advises the compiler that the variable in question will be heavily used.
    - The idea is that `register` variables are to be placed in machine registers, which may result in smaller and faster programs.
    - But compiler can ignore the advice.
    - This is how it's declared: `register int x;`.


### The C Preprocessor

The two most frequently used features are `#include`, to include the contents of a file during compilation, and `#define`, to replace a token by an  arbitrary sequence of characters.

An example of `max` macro define:

```
#define max(A, B) ((A) > B ? (A) : (B))
```

A use of `max` expands into in-line code. Each occurrence of a formal parameter (here `A` or `B`) will be replaced by the corresponding actual argument.

Names may be undefined with `#undef`, usually to ensure that a routine is really a function, not a macro.

For example, to make sure that the contents of a file `hdr.h` are included only once, the contents of the file are surrounded with a conditional like this:

```
#if !defined(HDR)
    #define HDR
    /* contents of hdr.h go here */
#endif
```

The first inclusion of `hdr.h` defines the name `HDR`; subsequent inclusions will find the name defined and skip down to the `#endif`.

This sequence tests the name `SYSTEM` to decide which version of a header to include:

```
#if SYSTEM == SYSV
    #define HDR "sysv.h"
#elif SYSTEM == BSD
    #define HDR "bsd.h"
#elif SYSTEM == MSDOS
    #define HDR "msdos.h"
#else
    #define HDR "default.h"
#endif
#include HDR
```

The `#ifdef` and `#ifndef` lines are specialized forms that test whether a name is defined. For `HDR` we could have used:

```
#ifndef HDR
#define HDR
```