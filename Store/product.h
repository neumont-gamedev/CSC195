#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Product
{
public:
	enum class eType
	{
		MOVIE,
		ALBUM,
		BOOK
	};

public:
	Product() 
	{
		id = uniqueId++;
	}

	virtual eType GetType() = 0;
	int GetId() { return id; }

	virtual void Read(std::istream& istream, std::ostream& ostream);
	virtual void Write(std::ostream& ostream);

	virtual void Read(std::ifstream& istream);
	virtual void Write(std::ofstream& ostream);

protected:
	eType type;
	int id;
	std::string name;

	static int uniqueId;
};

