// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "products.h"
#include <iostream>
using namespace std;

enum class eAction
{
    QUIT,
    LOAD,
    SAVE,
    ADD
};


int main()
{
    Products products;
   
    bool quit = false;
    do
    {
        cout << "Menu" << endl;
        cout << "0) Quit" << endl;
        cout << "1) Load" << endl;
        cout << "2) Save" << endl;
        cout << "3) Add" << endl;

        int selectInput;
        cin >> selectInput;
        std::cin.ignore(80, '\n');

        eAction action = static_cast<eAction>(selectInput);

        switch (action)
        {
        case eAction::QUIT:
            quit = true;
            break;
        case eAction::LOAD:
        {
            std::cout << "Enter filename to load: ";
            std::string filename;
            getline(cin, filename);
            products.Load(filename);
        }
            break;
        case eAction::SAVE:
        {
            std::cout << "Enter filename to save: ";
            std::string filename;
            getline(cin, filename);
            products.Save(filename);
        }
            break;
        case eAction::ADD:
        {
            std::cout << "Enter Type: ";
            int typeInput;
            std::cin >> typeInput;
            std::cin.ignore(80, '\n');

            Product* product = products.Create(static_cast<Product::eType>(typeInput));
            product->Read(std::cin, std::cout);
            products.Add(product);
        }
            break;
        default:
            break;
        }


    } while (!quit);
}

