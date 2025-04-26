/*
Step-by-step first program from learncpp.com
*/

#include<cstdlib>
#include <iostream>


int main()
{

    // Pre-value-initialize each variable we know we're going to use
    int x {};
    int doubleX {};

    std::cout << "Enter an integer: " << '\n';
    std::cin >> x;

    doubleX = x * 2;
    
    std::cout << "You entered: " << x << '\n';
    std::cout << "doubleX = " << doubleX << '\n';

    // Instead of storing doubleX as a variable in memory, simply execute the expresson with the * operator
    std::cout << "The more efficiently calculated doubleX = " << x * 2 << std::endl;
   
    return EXIT_SUCCESS;
}
