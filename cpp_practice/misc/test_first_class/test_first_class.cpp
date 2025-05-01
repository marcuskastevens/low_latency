#include <cstdlib>
#include <iostream>


class Node
{

public:

    double uninitializedData;
    double initializedData {};
    std::string name {"statistic_0"};
    std::tuple<std::string> dependencies {};  // {"dependency_0", "dependency_1"};

    Node(double newData)
    {
        initializedData = newData;
        std::cout << "Initialized data: " << initializedData << '\n';
        std::cout << "Uninitialized data: " << uninitializedData << std::endl;
    }

    ~Node()
    {
        std::cout << "Destroying Node" << std::endl;
    }

private:
    
    double x {};
    double y {};

};


class NoInstanceClass0
{

public:

    static void write0()
    {
        std::cout << "logging: " << typeid(NoInstanceClass0).name() << std::endl;
    }

private:

    // Disables the instantiation of this class by making the constructor a  private method 
    NoInstanceClass0(){}

};


class NoInstanceClass1
{

public:

    // Disables the instantiation of this class by making the constructor the delete operator
    NoInstanceClass1() = delete;    

    static void write1()
    {
        std::cout << "logging: " << __func__ << std::endl;
    }

};


int main()
{

    // Test the instantiation of Node
    Node node {Node(99)};
    Node* stackNodePointer = &node;
    Node* heapNodePointer = new Node(123);
    
    std::cout << node.initializedData << '\n';
    std::cout << stackNodePointer->initializedData << '\n';
    std::cout << heapNodePointer->initializedData << '\n';

    // Test the usage of non-initializable classes that exclusively impelment static methods 
    NoInstanceClass0::write0();
    NoInstanceClass1::write1();

    // Delete pointer early: since the stack pointer lives on the stack, not the heap, it will be automatically
    // deleted when it goes out of scope. Thus, there is no need to manually delete the pointer; if we do try to 
    // manually delete it, it will lead to undefined behavior.
    // The lesson here is a common rule of thumb in manual memory management: only delete what you new
    std::cout << "Deleting heap node pointer early: " << heapNodePointer->name << std::endl; 
    delete heapNodePointer;
    std::cout << "Deleting stack node pointer early: " << stackNodePointer->name << std::endl;
    delete stackNodePointer;

    return EXIT_SUCCESS;
}
