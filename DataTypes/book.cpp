#include "book.h"
#include <iostream>
using namespace std;

void Book::Write()
{
    cout << "book name: " << name << ", author: " << author << ", genre: " << EnumToString(genre) << ", year" << year << endl;
}
void Book::Read()
{
    cout << "Name: ";
    std::getline(std::cin, name);
    cout << "Author: ";
    std::getline(std::cin, name);

    cout << "Genre\n";
    cout << "0 = Mystery, 1 = Romance";
    int input;
    cin >> input;
    genre = static_cast<Genre>(input);
    cin.ignore(80, '\n');

    cout << "Year: ";
    cin >> year;
}

std::string Book::EnumToString(Genre genre)
{
	switch (genre)
	{
    case Book::Genre::mystery:
        return "Mystery";
        break;
    case Book::Genre::romance:
        return "Romance";
        break;
    case Book::Genre::fantasy:
        return "Fantasy";
        break;
    case Book::Genre::sci_fi:
        break;
    case Book::Genre::horror:
        break;
    case Book::Genre::historical:
        break;
    case Book::Genre::memoir:
        break;
	}

    return "";
}
