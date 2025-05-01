/*
Notes on functions:

- There are no nested functions in C++ (thank god).
- Functions that are not defined sequentially require a forward prototype declaration (i.e., a function header without 
a body), otherwise a compilation error will occur.
- Most often, forward declarations are used to tell the compiler about the existence of some function that has been 
defined in a different code file. Reordering isn’t possible in this scenario because the caller and the callee are in 
completely different files!
- In C++, the main() function supports three status codes (i.e., return values) 0, EXIT_SUCCESS, and EXIT_FAILURE. 
EXIT_SUCCESS and EXIT_FAILURE are preprocessor macros defined in the <cstdlib> header.
- If a function does not return the same type that is defined in its function header, undefined behavior will occur.
- Functions facilitate a central tenet of good programming: Don’t Repeat Yourself (often abbreviated DRY).
- The (snarky) opposite of DRY is WET (“Write everything twice”).

Notes on parameters and arguments: 

A function parameter is a variable used in the header of a function. Function parameters work almost identically to 
variables defined inside the function, but with one difference: they are initialized with a value provided by the 
caller of the function, which is the argument. An argument is a value that is passed from the caller to the function 
when a function call is made.

When a function is called, all of the parameters of the function are created as variables, and the value of each of 
the arguments is copied into the matching parameter (using copy initialization). This process is called pass by value. 
Function parameters that utilize pass by value are called value parameters.

Notes on scope:

- The scope of a variable is defined by curly brackets.
- Upon the close of curly brackets, objects that go out of scope are destroyed, and, if implemented, their destructors 
are called.
- Lifetime of a variable is a runtime property (i.e., when the program is executed, not compiled).
- Scope of a variable is a compile time peroperty.
*/

#include <cstdlib>
#include <iostream>


// Since this function returns a status code of type int instead of a char, undefined behavior will ensue
char getChar()
{
    return EXIT_SUCCESS;
}


// This is an example of a forward function prototype declaration - a forward declaration omits the function body 
double calculateSquare(double x);


int main()
{
    getChar();
    std::cout << calculateSquare(10.00) << std::endl;
    return EXIT_SUCCESS;    
}


// Implement the function non-sequentially and leverage the forward declaration
double calculateSquare(double x)
{
    return x * x;
}
