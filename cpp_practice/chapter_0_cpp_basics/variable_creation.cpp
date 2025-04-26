/*
Notes on value creation:

Initialized = The object is given a known value at the point of definition.
Assignment = The object is given a known value beyond the point of definition.
Uninitialized = The object has not been given a known value yet.
*/

#include <cstdlib>
#include <iostream>


int main(){

    // "Define" (which is a special declaration) a variable (a named object) - this statement represents a "default-initialized" or "uninitialized" variable
    int x;

    // This "uninitialized" variable is allocated memory, but given a garbage value that does not mean anything, 
    // likely whatever was previously in that memory address, creating undefined behavior
    std::cout << x << '\n';

    // This statement performs "value-initialization" (empty curly braces)
    int y {};
    
    // "Assign" a variable 
    x = 0;
    y = 1;
    std::cout << x << y << '\n';

    // "Initialize" a variable - this statement performs "copy-initialization" (= value)
    int z = 0;
    std::cout << z << std::endl;

    // Purposefully unused variable to avoid compiler warnings - this statement performs "direct-list-initialization" (filled curly braces)
    [[maybe_unused]] double PHI {3.14159265};

    // Mis-labled unused variable which will generate compiler warnings - this statement performs "direct-initialization" (filled parentheses)
    double E (2.53235);
    
    return EXIT_SUCCESS;
}
