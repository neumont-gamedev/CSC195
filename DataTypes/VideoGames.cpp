#include "VideoGames.h"
#include <iostream>

using namespace std;

std::string VideoGame::getGenre() {
    switch (genre)
    {
    case COMEDY:
        return "Comedy";
        break;
    case HORROR:
        return "Horror";
        break;
    case SURVIVAL_HORROR:
        return "Survival Horror";
        break;
    case MYSTERY:
        return "Mystery";
        break;
    case FANTASY:
        return "Fantasy";
        break;
    case STORY_BASED:
        return "Story Based";
        break;
    default:
        return "None";
        break;
    }
}

void VideoGame::setGenre(int newGenre)
{
    genre = static_cast<eGenre>(newGenre); // convert int value to enum eGenre value
}

void VideoGame::Write()
{
    cout << "Name: " << getName() << endl;
    cout << "Price: $" << getPrice() << endl;
    cout << "Release Year: " << getReleaseYear() << endl;
    cout << "Company it was created by: " << getCompanyCreated() << endl;
    cout << "Genre: " << getGenre() << endl;
}

void VideoGame::Read()
{
    cout << "Name: ";
    std::getline(std::cin, name);
    cout << "Price: $";
    cin >> price;
    cin.ignore(80, '\n');
    cout << "Release Year: ";
    std::getline(std::cin, releaseYear);
    cout << "Company it was created by: ";
    std::getline(std::cin, companyCreated);
    cout << "For the genre, type 1 for comedy, 2 for horror, 3 for survival horror, 4 for mystery, 5 for fantasy, and 6 for story based.\n\nGenre: ";
    int input;
    cin >> input;
    setGenre(input);
}