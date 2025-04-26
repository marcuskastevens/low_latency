/*
Notes on undefined behavior:

Undefined behavior (often abbreviated UB) is the result of executing code whose behavior is not well-defined by the 
C++ language.

Code implementing undefined behavior may exhibit any of the following symptoms:

- Your program produces different results every time it is run.
- Your program consistently produces the same incorrect result.
- Your program behaves inconsistently (sometimes produces the correct result, sometimes not).
- Your program seems like it’s working but produces incorrect results later in the program.
- Your program crashes, either immediately or later.
- Your program works on some compilers but not others.
- Your program works until you change some other seemingly unrelated code.
*/

#include <cstdlib>
#include <iostream>


int main(){

    /* 
    "Define" (which is a special declaration) a variable (a named object) - this statement represents a 
    "default-initialized" or "uninitialized" variable
    */
    int x;

    /* 
    This "uninitialized" variable is allocated memory, but given a garbage value that does not mean anything, 
    likely whatever was previously in that memory address, creating undefined behavior.

    In this case, the C++ language doesn’t have any rules determining what happens if you use the value of a variable 
    that has not been given a known value. Consequently, if you actually do this, undefined behavior will result.
    */ 
    std::cout << x << '\n';

    return EXIT_SUCCESS;
}
