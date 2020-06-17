// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

// base.h
class Base
{
public:
    Base() {}
    Base(std::string name)
    {
        this->name = name;
    }

    virtual void Write() { std::cout << "Base" << std::endl; }

protected:
    std::string name;
    int year;
};

// derivedA.h
// #include "base.h"
class DerivedA : public Base
{
public:
    DerivedA() {}
    DerivedA(std::string name) : Base(name) {}
    DerivedA(std::string name, int unique) //: Base(name) 
    {
        this->name = name;
        this->unique = unique;
    }

    int GetUnique() { return unique; }
    void SetUnique(int unique) { this->unique = unique; }

    void Write() { std::cout << "Derived A: " << unique << std::endl; }

protected:
    int unique = 0;
};


// derivedB.h
// #include "base.h"
class DerivedB : public Base
{
public:
    DerivedB() {}
    DerivedB(std::string name) : Base(name) {}

    void Write() { std::cout << "Derived B" << std::endl; }
};

int main()
{
    DerivedA a;
    a.Write();

    DerivedB b;
    b.Write();

    //std::vector<int> n = { 5, "hi", 7.0f };

    std::vector<Base*> objects;

    // read
    Base* object = new DerivedB("b class");
    // object->Read();
    objects.push_back(object);

    object = new DerivedA("a class");
    objects.push_back(object);

    object->Write();

    // write
    for (Base* object : objects)
    {
        object->Write();
    }
}
