/*
Notes on implementaion-defined behavior:

A specific compiler and the associated standard library it comes with are called an implementation 
(as these are what actually implements the C++ language and converts source code into machine code). 
In some cases, the C++ language standard allows the implementation to determine how some aspect of the language 
will behave, so that the compiler can choose a behavior that is efficient for a given platform. 

Notes on unspecified behavior:

Unspecified behavior is almost identical to implementation-defined behavior in that the behavior is left up to the 
implementation (compiler) to define, but the implementation is not required to document the behavior.

We generally want to avoid implementation-defined and unspecified behavior, as it means our program may not work as 
expected if compiled on a different compiler (or even on the same compiler if we change project settings that affect 
how the implementation behaves!)
*/

#include <cstdlib>
#include <iostream>


int main()
{
	// How many bytes of memory an int value takes (2 or 4) is platform dependent  
	std::cout << sizeof(int) << '\n'; 

	return EXIT_SUCCESS;
}
