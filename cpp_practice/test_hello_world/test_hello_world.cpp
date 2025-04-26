#include <vector>
#include <string>
#include <iostream>


const int MY_CONSTANT = 0;


int test_constants(){
    
    std::cout << MY_CONSTANT << '\n';
    std::cout << EXIT_SUCCESS << '\n';
    std::cout << EXIT_FAILURE << '\n';

    return EXIT_SUCCESS;

}


int test_vector() {


    std::vector<std::string> myVector {"Hello", "C++", ",", "I", "am", "happy", "to", "be", "learning", "your", "secrets", ";)"}; 

    for (const std::string& word: myVector){
        std::cout << word << ' ';
    }

    std::cout << '\n';

    return EXIT_SUCCESS;

}


int main() {

    std::cout << "Using C++ Version: " << __cplusplus << '\n';
    std::cout << MY_CONSTANT << '\n';

    std::cout << "Hello World" << std::endl;

    test_vector();
    test_constants();

    return EXIT_SUCCESS;

}
