# Pointers and Arrays

A pointer is a variable that contains the address of a variable. Pointers are often used because it leads to more compact and efficient code. Pointers and arrays are closely related.

Proper type for a generic pointer is now `char *` (pointer to char).


## Pointers and Addresses

One common situation is that any byte can be a `char`, a pair of one-byte cells can be treated as a `short` integer, and four adjacent bytes form a `long`. A **pointer** is a group of cells (often two or four) that can hold an address.

If `c` is a `char` and `p` is pointer that points to `c`'s address we'll right it like this: `p = &c;`. This way `p` is set to _point to_ `c`. The `&` operator only applies to objects in memory: variables and array elements. It cannot be applied to expressions, constants, or register variables.

The unary operator `*` is the _dereferencing_ operator; when applied to a pointer, it accesses the object the pointer points to.

You should also note the implication that a pointer is constrained to point to a particular kind of object: every pointer points to a specific data type. (There is one exception: a pointer to `void` is used to hold any type of pointer but cannot be dereferenced itself).

`(*ip)++` The parentheses are necessary in this last example; without them, the expression would increment ip instead of what it points to, because unary operators like * and ++ associate right to left.