# Pointers and Arrays

A pointer is a variable that contains the address of a variable. Pointers are often used because it leads to more compact and efficient code. Pointers and arrays are closely related.

Proper type for a generic pointer is now `char *` (pointer to char).


## Pointers and Addresses

One common situation is that any byte can be a `char`, a pair of one-byte cells can be treated as a `short` integer, and four adjacent bytes form a `long`. A **pointer** is a group of cells (often two or four) that can hold an address.

If `c` is a `char` and `p` is pointer that points to `c`'s address we'll right it like this: `p = &c;`. This way `p` is set to _point to_ `c`. The `&` operator only applies to objects in memory: variables and array elements. It cannot be applied to expressions, constants, or register variables.

The unary operator `*` is the _dereferencing_ operator; when applied to a pointer, it accesses the object the pointer points to.

You should also note the implication that a pointer is constrained to point to a particular kind of object: every pointer points to a specific data type. (There is one exception: a pointer to `void` is used to hold any type of pointer but cannot be dereferenced itself).

`(*ip)++` The parentheses are necessary in this last example; without them, the expression would increment `ip` instead of what it points to, because unary operators like `*` and `++` associate right to left.

The way to swap two `int` values will be for the calling program to pass _pointers_ to the values to be swapped. For example:

```
/* interchange *px and *py */
void swap(int *px, int *py)
{
    int tmp;

    tmp = *px;
    *px = *py;
    *py = tmp;
}
```

When an array name is passed to a function, what is passed is the location of the initial element. Within the called function, this argument is a local variable, and so an array name parameter is a pointer, that is, a variable containing an address.

If `p` is a pointer to some element of an array, then `p++` increments `p` to point to the next element, and `p+=i` increments it to point `i` elements beyond where it currently does.

- `alloc(n)` , returns a pointer to `n` consecutive character positions, which can be used by the caller of alloc for storing characters.
- `afree(p)` , releases the storage thus acquired so it can be re-used later.
- The routines are _rudimentary_ because the calls to `afree` must be made in the opposite order to the calls made on `alloc`.
    - Storaged managed by them is a stack (LIFO).
- The standard library provides analogous functions called `malloc` and `free` that have no such restrictions.

Pointers may be compared. If `p` and `q` point to members of the same array, then relations like == , != , < , >= , etc., work properly. Foe xample if `p < q` is `true` this means that `p` points to the earlier element of the array than `q` does.

A pointer and an integer may be added or subtracted: `p + n` means that the adress of the `n`-th object beyond the one `p` currently points to. This is true regardless of the kind of object `p` points to; n is scaled according to the size of the objects `p` points to, which is determined by the declaration of `p`. If an `int` is four bytes, for example, the `int` will be scaled by four.

Pointer subtraction is also valid: if `p` and `q` point to elements of the same array, and `p < q` , then `q-p+1` is the number of elements from `p` to `q` inclusive.

## Character Pointers and Functions

A _string constant_ written "Hello, World!" is an array of characters, which is terminated with the null character `'\0'` so the program finds the end. The length is thus one more than the number or characters between the double quotes.

- C does not provide any operators for processing an entire string of characters as a unit.

There is an important difference between these definitions:

```
char amessage[] = "now is the time"; /* an array */
char *pmessage = "now is the time"; /* a pointer */
```

- If `s` and `t` are strings `s=t` will copy the pointer but not the characters.

## Pointer Arrays

Since pointers are variables themselves, they can be stored in arrays just as other variables can. For example: `char *lineptr[MAXLINES]` says that `lineptr` is an array of `MAXLINES` elements, each element of which is a pointer to a `char`. That is, `lineptr[i]` is a character pointer, and `*lineptr[i]` is the character it points to, the first character of the `i`-th saved text line.

## 2D Arrays and Pointers

Thus if the 2d-array with 2 rows and 13 columns `daytab` is to be passed to a function `f` , the declaration of f would be: `f(int daytab[2][13]) { ... }` or it could be `f(int daytab[][13]) { ... }`. ince the number of rows is irrelevant, or it could be `f(int (*daytab)[13]) { ... }` which says that the parameter is a pointer to an array of 13 integers. The parentheses are necessary since brackets [] have higher precedence than *.

## Command Line

`main` is called with two arguments: 

1. (conventionally called `argc` , for argument count) is the number of command-line arguments the program was invoked with.
2. ( `argv` , for argument vector) is a pointer to an array of character strings that contain the arguments, one per string.

for C programs on UNIX systems is that an argument that begins with aminus sign introduces an optional flag or parameter. If we choose `-x` (for "except") to signal the inversion, and `-n` ("number") to request line numbering, then the command `find -x -npattern` will print each line that doesn't match the pattern, preceded by its line number. Optional arguments should be permitted in any order, and the rest of the program should be independent of the number of arguments that we present.