#include <cstdlib>
#include <iostream>

const int N_STANDARDS = 7;
const long STANDARD_CODES[N_STANDARDS] = { 199711L, 201103L, 201402L, 201703L, 202002L, 202100, 202612L};
const std::string STANDARD_NAMES[N_STANDARDS] = { "Pre-C++11", "C++11", "C++14", "C++17", "C++20", "C++23", "C++26" };


long getCPPStandardCode(){
    return __cplusplus;
}


bool validateCPPStandardCode(const long& cppStandardCode){
    if (cppStandardCode == -1){
        std::cout << "Error: Unable to determine C++ Standard" << std::endl;
        return false;
    }
    return true;
}


std::string getCPPStandardName(const int& i){
    return STANDARD_NAMES[i];
}


int logCPPStandardName(const std::string& cppStandardName){
    std::cout << "C++ Standard = " << cppStandardName << std::endl;
    return EXIT_SUCCESS; 
}


int main(){

    const long cppStandardCode = getCPPStandardCode();
    
    // Fail early and modularize
    if (validateCPPStandardCode(cppStandardCode) == false){
        return EXIT_FAILURE;
    }

    // Exit early and modularize
    for (int i = 0; i < N_STANDARDS; i++){
        if (cppStandardCode == STANDARD_CODES[i]){
            std::string cppStandardName = getCPPStandardName(i);
            logCPPStandardName(cppStandardName);
            return EXIT_SUCCESS;
        }
    }

    // Handle all other conditions
    std::cout << "Unsupported C++ Standard Code: " << cppStandardCode << std::endl;

    return EXIT_FAILURE;
}
