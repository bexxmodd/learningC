#include <stdio.h>
#include <stdlib.h>

#define NSYM 100

struct {
    char *name;
    int flags;
    int utype;
    union {
        int ival;
        float fval;
        char *sval;
    } u;
} symtab[NSYM];

int main()
{
    // the member ival is referred to as
    symtab[0].u.ival;

    // the first char in sval as
    *symtab[0].u.sval;
    // or
    symtab[0].u.sval[0];

    // A union may only be initialized with a value of the 
    // type of its first member; thus union u described above
    // can only be initialized with an integer value.
}