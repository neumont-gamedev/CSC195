#pragma once
#include <string>


class Book {
public:
    enum class Genre
    {
        mystery,
        romance,
        fantasy,
        sci_fi,
        horror,
        historical,
        memoir
    };

public:
    Book() {}
    Book(std::string name, std::string author, Genre genre, int year)
    {
        this->name = name;
        this->author = author;
        this->genre = genre;
        this->year = year;
    }
    void Write();
    void Read();

    std::string EnumToString(Genre genre);

private:
    std::string name;
    std::string author;
    Genre genre;
    int year;
};
