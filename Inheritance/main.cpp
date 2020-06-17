// Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

class Parent
{
public:
    Parent() 
    {
        std::cout << "Parent Constructor" << std::endl;
        count++;
    }

    virtual std::string GetName() { return "Parent"; }
    static std::string GetClassName() { return "ParentClass"; }

public:
    static int count;

protected:
    int data1;
};

int Parent::count = 0;

class Child : public Parent
{
public:
    Child() 
    {
        std::cout << "Child Constructor" << std::endl;
    }

    std::string GetName() override { return "Child"; }

protected:
    int data2;
};

int main()
{
    Parent parent;
    Child child;

    // get size of class instance
    std::cout << sizeof(parent) << std::endl;
    std::cout << sizeof(child) << std::endl;

    // set pointer to object addresses
    Parent* pParent = &parent;
    Parent* pChild = &child;

    std::cout << Parent::GetClassName() << std::endl;
    std::cout << Parent::count << std::endl;

    // different ways to access methods/members from an object or pointer to an object
    //parent.GetName(); // object
    //(*pParent).GetName(); // * to deference pointer to get object, then use dot to access method like above
    //pParent->GetName();   // use -> to access method of object pointed at
    
    // access static method
    //Parent::GetClassName();
    std::cout << pParent->GetName() << std::endl;
    std::cout << pChild->GetName() << std::endl;
    //for (auto iter = parents.begin(); iter < parents.end(); iter++)


    std::vector<Parent*> parents;
    parents.push_back(pParent);
    parents.push_back(pChild);
    
    for (Parent* parent : parents)
    {
        std::cout << parent->GetName() << std::endl;
    }
}

