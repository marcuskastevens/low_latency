/*
Notes on std::exit vs. std::abort:

If the program terminates (via std::exit) then we will have lost our call stack and any debugging information that 
might help us isolate the problem. std::abort is a better option for such cases, as typically the developer will be 
given the option to start debugging at the point where the program aborted.

Notes on preconditions, invariants, and postconditions:
- Preconditions must be true before executing an action 
- Invariants must be true while executing an action 
- Postconditions must be true after executing an action

Notes on assert:

Assert provides built-in support for condition evaluation, logging, and debugging by using std::abort which preserves 
the state of the program upon termination. 

Notes on static_assert:

A static assert is evalutated at COMPILE time instead of RUNTIME! Unlike assert which s declared in the <cassert> 
header, static_assert is a reserved keyword and is readily available. Since the static assertion is executed at compile
time, there is no runtime overhead, and it can only be executed on constants.

Notes on NDEBUG:

Asserts come with a minor performance cost and are generally used for testing/debugging. Ideally, production systems
omit all asserts when executed. By defining the preprocessor macro NDEBUG, we can disable all assertions for production 
builds. 

To do so, place one of the following on its own line before any #includes: 
#define NDEBUG (to disable asserts) or #undef NDEBUG (to enable asserts).

Notes on error handling:

Asserts do not replace the need for graceful error handling. We should natively control for all possible errors and 
ensure the program has a contingency plan for when things go wrong. Asserts must be used IN ADDITION to error 
handling logic. For example, the program should not abruptly terminate if there is an unclosed database connection
or open file, which could lead to data corruption. It should identify the error, exeucte cleanup and safety tasks, and
then terminate.   
*/

#undef NDEBUG // #define NDEBUG
#include<cmath>
#include<cassert>
#include<cstdlib>
#include<iostream>

const double VALID_GRAVITY {9.8};
const double INVALID_GRAVITY {-9.8};


double calculateTimeUntilObjectHitsGround(double initialHeight, double gravity)
{
    /*
    The object won't reach the ground unless there is positive gravity - abort and debug if false.
    Use the logical AND operator to add a more descriptive message to the assertion.
    */ 
    assert(gravity > 0.0 && "Gravity must be positve!");

    // If the object has hit the ground or is buried underneath the ground, return
    if (initialHeight < 0.0)
    {
        return 0;
    }

    return std::sqrt((2.0 * initialHeight) / gravity);
}


int main()
{
    // Test valid gravity
    std::cout 
        << "Took " 
        << calculateTimeUntilObjectHitsGround(100.00, VALID_GRAVITY) 
        << " second(s) to hit the ground!" 
        << '\n';

    // Test invalid gravity
    std::cout 
        << "Took " 
        << calculateTimeUntilObjectHitsGround(100.00, INVALID_GRAVITY) 
        << " second(s) to hit the ground!" 
        << '\n';

    // Illustrate how static_assert works
    static_assert(INVALID_GRAVITY > 0.00, "Gravity must be positive!");

    return EXIT_SUCCESS;
}
