#include <cstdlib>
#include <iostream>


class Node
{
public:   
    std::string name {};
    Node() = default;
    Node(const std::string& newName)
    {
        name = newName;
    }
};


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
};


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
};


int main()
{
    Parent parent {Parent("marcus")};
    Child child {Child("marcus_jr")};

    parent.child = child;
    child.parent = parent;

    std::cout << parent.child.name << '\n';
    std::cout << child.parent.name << std::endl;

    return EXIT_SUCCESS;
}
