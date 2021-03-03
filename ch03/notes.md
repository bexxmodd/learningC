# Chapter 3 - Control Flow

The `switch` statement is a multi-way decision that tests whether an expression matches one of a number of constant integer values, and branches accordingly.

cases serve just as labels, after the code for one case is done, execution _falls through_ to the next unless you take explicit action to escape

ith the exception of multiple labels for a single computation, fall-throughs should be used sparingly, and commented.

As a matter of good form, put a break after the last case (the default here) even though it's logically unnecessary. Some day when another case gets added at the end, this bit of defensive programming will save you.

The `for` statement:

```
for (expr 1 ; expr 2 ; expr 3 )
    statement
```

Grammatically, the three components of a for loop are expressions. Most commonly, _expr1_ and _expr3_ are assignments or function calls and _expr2_ is a relational expression. Any of the three parts can be omitted, although the semicolons must remain.