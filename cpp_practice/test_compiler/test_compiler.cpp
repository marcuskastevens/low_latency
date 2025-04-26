#include <vector>
#include <string>
#include <cstdlib>   
#include <cstddef>
#include <iostream>


// Calculates the dot product by copying the values of X and y in memory - inefficient use of memory 
std::vector<double> dotByValue(const std::vector<double> X, const std::vector<double> y){
    
    // Pre-allocate memory for y_hat by initializing it with the size of y
    std::vector<double> y_hat(y.size());
    
    for (std::size_t i = 0; i < X.size(); i++){
        y_hat[i] = X[i] * y[i];
    }

    return y_hat;
}


// Calculates the dot product by passing in the memory reference of the pre-existing vectors
// By passing a constant reference, this renders the reference as read-only, 
// creating a safe way to access pre-existing memory
std::vector<double> dotByReference(const std::vector<double>& X, const std::vector<double>& y){
    
    // Pre-allocate memory for y_hat by initializing it with the size of y
    std::vector<double> y_hat(y.size());
    
    for (std::size_t i = 0; i < X.size(); i++){
        y_hat[i] = X[i] * y[i];
    }

    return y_hat;
}


// Calculates the dot product between two C‐style arrays of length n
std::vector<double> dotByPointer(const double* X, const double* y, std::size_t n){
    
    // Pre-allocate result with n elements
    std::vector<double> y_hat(n);

    for (std::size_t i = 0; i < n; i++) {
        y_hat[i] = X[i] * y[i];
    }

    return y_hat;
}


int main() {

    // Initialize two vectors of equal length
    std::vector<double> X = {2.0, 3.0, 4.0, 5.0};
    std::vector<double> y = {2.0, 3.0, 4.0, 5.0};

    // Calculate the dot product between X and y 
    std::vector<double> yHatByValue = dotByValue(X, y);
    std::vector<double> yHatByReference = dotByReference(X, y);
    std::vector<double> yHatByPointer = dotByPointer(X.data(), y.data(), X.size());

    // By value
    std::cout << '\n' << "By value:" << '\n';
    std::cout << '[' << '\n';
    for (int i = 0; i < yHatByValue.size(); i++){
        std::cout << "   [" << yHatByValue[i] << "]," << '\n';
    }
    std::cout << ']' << std::endl;

    // By memory reference
    std::cout << '\n' << "By memory reference:" << '\n';
    std::cout << '[' << '\n';
    for (int i = 0; i < yHatByReference.size(); i++){
        std::cout << "   [" << yHatByReference[i] << "]," << '\n';
    }
    std::cout << ']' << std::endl;

    // By pointer
    std::cout << '\n' << "By pointer:" << '\n';
    std::cout << '[' << '\n';
    for (int i = 0; i < yHatByPointer.size(); i++){
        std::cout << "   [" << yHatByPointer[i] << "]," << '\n';
    }
    std::cout << ']' << std::endl;

    return EXIT_SUCCESS;
}
