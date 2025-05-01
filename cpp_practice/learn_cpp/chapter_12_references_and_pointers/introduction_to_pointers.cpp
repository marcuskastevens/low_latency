/*

Notes on pointers:

A pointer is an object that holds a memory address (typically of another variable) as its value. 
This allows us to store the address of some other object to use later. A type that specifies a pointer (e.g., int*) is 
called a pointer type. Much like reference types are declared using an ampersand (&) character, pointer types are 
declared using an asterisk (*): Since pointers hold addresses, when we initialize or assign a value to a pointer,
that value has to be an address. Much like the type of a reference has to match the type of object being referred to, 
the type of the pointer has to match the type of the object being pointed to.

The & symbol tends to cause confusion because it has different meanings depending on context:

When following a type name, & denotes an lvalue reference: int& ref.
When used in a unary context in an expression, & is the address-of operator: std::cout << &x.
When used in a binary context in an expression, & is the Bitwise AND operator: std::cout << x & y.

Getting the address of a variable isn’t very useful by itself.

The most useful thing we can do with an address is access the value stored at that address. 
The dereference operator (*) (also occasionally called the indirection operator) returns the value at a given memory 
address as an lvalue.

Given a memory address, we can use the dereference operator (*) to get the value at that address (as an lvalue).

The address-of operator (&) and dereference operator (*) work as opposites: address-of gets the address of an object, 
and dereference gets the object at an address.

We can use assignment with pointers in two different ways:
- To change what the pointer is pointing at (by assigning the pointer a new address)
- To change the value being pointed at (by assigning the dereferenced pointer a new value)

Pointers and references both provide a way to indirectly access another object. The primary difference is that with 
pointers, we need to explicitly get the address to point at, and we have to explicitly dereference the pointer to get 
the value. With references, the address-of and dereference happens implicitly.

There are some other differences between pointers and references worth mentioning:

References must be initialized, pointers are not required to be initialized (but should be).
References are not objects, pointers are.
References can not be reseated (changed to reference something else), pointers can change what they are pointing at.
References must always be bound to an object, pointers can point to nothing.
References are “safe” (outside of dangling references), pointers are inherently dangerous.
*/

#include<cstdlib>
#include<iostream>


int main()
{
    // Assume x is assigned RAM memory address 140
    char x {'a'}; 
    char y {'b'};
    
    // ref is an lvalue reference to x's value at memory address 140 (when used with a type, & means the lvalue ref)
    char& ref {x};

    // Pointer

    std::cout << "x's value = " << x << '\n';   
    std::cout << "ref = " << ref << '\n';  
    std::cout << "&x = " << &x << '\n';
    std::cout << "*&x = " << *&x << std::endl;

    // An uninitialized pointer (holds a garbage address)
    char* ptr;       
    
    // A null pointer
    char* ptr2{};     

    // A pointer initialized with the address of variable x
    char* ptr3{ &x }; 
    std::cout << *ptr3 << '\n';

    // Change what a pointer points to (by assigning the pointer to a new memory address)
    ptr3 = &y;
    std::cout << *ptr3 << '\n';

    // Change the value being pointed at (by assigned the dereferenced pointer a new value)
    *ptr3 = 'c';
    std::cout << *ptr3 << '\n';

    // Check that y's value was indeed updated when changing the value that was pointed at by ptr3
    std::cout << y << std::endl;

    return EXIT_SUCCESS;
}
