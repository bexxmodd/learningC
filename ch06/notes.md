# Chapter 6 - Structures

Struct defined in a following way:

```
struct point {
    int x;
    int y;
}
```

A structure declaration that is not followed by a list of variables reservers no storage; it merely describes a template or shape of a structure.

For example: `struct point pt;` defines a variable `pt` which is a structure of type `point`. Structure can be initialized by following way: `struct maxpt = {320, 200};`.

- The only legal operations on a structure are copying it or assigning to it as a unit, taking its address with `&`, and accessing its members.
- Structures may not be compared.
- A structure may be initialized by a list of constant member values.
- If a large structure is to be passed to a function, it is generally more efficient to pass a pointer than to copy the whole structure.

Pointers to structures are so frequently used that an alternative notion is provided as shorthand. `p -> member_of_structure` refers to a particular member of a structure.

Both . and -> associate from left to right, so if we have
```
struct rect r, *rp = &r;
```

then these four expressions are equivalent:
```
r.pt1.x
rp->pt1.x
(r.pt1).x
(rp->pt1).x
```

