#pragma once
#include <string>

enum eGenre {
    NONE,
    COMEDY,
    HORROR,
    SURVIVAL_HORROR,
    MYSTERY,
    FANTASY,
    STORY_BASED
};

class VideoGame
{
public:
    VideoGame()
    {
        name = "unknown";
        price = 0;
        releaseYear = "unknown";
        companyCreated = "unknown";
        genre = NONE;
    }

    VideoGame(std::string name_, int price_, std::string releaseYear_,std::string companyCreated_,eGenre genre_ )
    {
        name = name_;
        price = price_;
        releaseYear = releaseYear_;
        companyCreated = companyCreated_;
        genre = genre_;
    }

    void Write();
    void Read();

    void setName(std::string newName) { name = newName; }
    std::string getName() { return name; }

    int getPrice() { return price; }
    void setPrice(int newPrice) { price = newPrice; }

    std::string getReleaseYear() { return releaseYear; }
    void setReleaseYear(std::string newReleaseYear) { releaseYear = newReleaseYear; }

    std::string getCompanyCreated() { return companyCreated; }
    void setCompanyCreated(std::string newCompanyCreated) { companyCreated = newCompanyCreated; }

    std::string getGenre();
    void setGenre(int newGenre);

private:
    std::string name;
    int price;
    std::string releaseYear;
    std::string companyCreated;
    eGenre genre;
}; 
