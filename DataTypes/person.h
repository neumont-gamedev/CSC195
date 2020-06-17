#pragma once
#include <string>
#include <iostream>

enum class eHairColor
{
	BROWN,
	BLONDE,
	RED
};

enum class eGenre
{
	COMEDY,
	DRAMA,
	HORROR
};

class Person
{
public:
	Person();
	Person(std::string _name, int _age, float _height, eHairColor _hairColor);
	void Write();
	void Read();

private:
	std::string name;
	int age;
	float height;
	eHairColor hairColor;
};

