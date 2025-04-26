/*
Notes on expressions:

In general programming, an expression is a non-empty sequence of literals, variables, operators, and function calls 
that produce a value. Expressions are not full statements by themselves as statements require semicolons. Statements 
use expressions to form complete instruction sets. Functions use statements to perform a series of actions.

The process of executing an expression is called evaluation, and the resulting value produced is called the result of 
the expression (also sometimes called the return value).

The result of an expression is one of the following:
- Value
- Object or function
- Nothing
*/

#include <cstdlib>
#include <iostream>


int getFive()
{
    return 5;
}


// Notice that the initializations make use of a variety of elements: literals, variables, operators, and function calls
int main()
{
    int a {2};
    int b {2 + 3};
    int c {(2 * 3) + 4};
    int d {b};
    int e {getFive()};
    return EXIT_SUCCESS;
}
