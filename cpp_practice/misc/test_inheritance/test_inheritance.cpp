#include <cstdlib>
#include <iostream>


class Node
{

public: 

    std::string name {};

    Node() = default;

    // When implementing a class with any virtual function/method, we must also make the destructor virtual, otherwise 
    // memory leaks and undefined behavior will ensue since the subclasses' destructors will not be invoked!
    virtual ~Node() = default;

    Node(const std::string& newName)
    {
        name = newName;
    }   

    // Using a virtual method allows us to overwrite its behavior in child classes that inherit from Node.
    // Virtual functions and methods leverage dynamic dispatch which is controlled by a vtable, which maps each base 
    // class's method to each subclass's method.
    virtual void updateName(const std::string& newName)
    {
        std::cout << "Calling updateName in Node" << std::endl;
        name = newName;
    }

};


// Parent class that inerhits from Node
class Parent : public Node
{

public:   
    
    Node child {};

    Parent(const std::string& newName)
    {
        name = newName;
    }
    
    void setChild(const Node& newChild)
    {
        child = newChild;
    }

    void updateName(const std::string& newName)
    {
        std::cout << "Calling updateName in Parent" << std::endl;
        name = newName;
    }

};


// Child class that inerhits from Node
class Child : public Node
{

public:

    Node parent {};

    Child(const std::string& newName)
    {
        name = newName;
    }
    
    void setParent(const Node& newParent)
    {
        parent = newParent;
    }

    void updateName(const std::string& newName)
    {
        std::cout << "Calling updateName in Child" << std::endl;
        name = newName;
    }

};


int main()
{
    Parent parent {Parent("marcus")};
    Child child {Child("marcus_jr")};

    parent.child = child;
    child.parent = parent;

    std::cout << parent.child.name << '\n';
    std::cout << child.parent.name << std::endl;

    parent.updateName("marcus_sr");
    child.updateName("marcus");

    std::cout << parent.child.name << '\n';
    std::cout << child.parent.name << std::endl;

    return EXIT_SUCCESS;
}
