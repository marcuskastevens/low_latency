/*
Notes on declaration vs. definition:

A declaration tells the compiler about the existence of an identifier and its associated type information, not
necessarily its implementation. 

A definition is a declaration that actually implements (for functions and types) or instantiates (for variables) the 
identifier. 

In C++, all definitions are declarations. Therefore int x; is both a definition and a declaration. Conversely, not all 
declarations are definitions. Declarations that aren’t definitions are called pure declarations. Types of pure 
declarations include forward declarations for function, variables, and types.

When the compiler encounters an identifier, it will check to ensure use of that identifier is valid 
(e.g., that the identifier is in scope, that it is used in a syntactically valid manner, etc…). Declarations allow the 
compiler to ensure that an identifier is being used properly; however, sometimes, actual implementations/definitions, 
not only pure declarations, are required by the compiler. If there is a pure declaration, but no definition, a linkage
error will be thrown.

Declaration vs. definition vs. initialization overall:

Declaration: Tells compiler about an identifier and its associated type information.
Definition:	Implements a function or instantiates a variable. Definitions are also declarations.
Pure declaration: A declaration that isn’t a definition.
Initialization:	Provides an initial value for a defined object.

Notes on the "One Definition Rule" (ODR):
- Within a file, each function, variable, type, or template in a given scope can only have one definition.
- Within a program, each function or variable in a given scope can only have one definition.
- Types, templates, inline functions, and inline variables are allowed to have duplicate definitions in different files, 
so long as each definition is identical.
- Violating part 1 of the ODR will cause the compiler to issue a redefinition compilation error. 
- Violating ODR part 2 will cause the linker to issue a redefinition error. 
- Violating ODR part 3 will cause undefined behavior.
*/

#include <cstdlib>
#include <iostream>


// This is a forward function prototype declaration, a pure declaration
int function0(int x);


// This is a function definition
int function1(int x)
{
    return x;
};


int main()
{

    // Define a variable
    int x;

    // Initialize a variable
    int y {10};

    // Call the originally forward declared function 
    x = function0(y);

    std::cout << x << '\n';
    std::cout << function1(y) << std::endl;

    return EXIT_SUCCESS;
}


int function0(int x)
{
    return x * 2;
}
