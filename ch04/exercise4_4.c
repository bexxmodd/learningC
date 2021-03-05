#include <stdio.h>

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */


/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop()
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* peek: return top value without removing */
double peek(double f)
{
    if (sp > 0)
        return val[sp];
    else
        printf("error: stack is empty\n");
        return 0.0;
}

/* clear: clear the contents of stack */
void clear()
{
    for (sp; sp > -1;)
        val[sp--] = '\0';
}

/* swap: replace top and second element's order */
void swap()
{
    double first = pop();
    double second = pop();
    push(first);
    push(second);

}