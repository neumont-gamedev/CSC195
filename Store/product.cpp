#include "product.h"
using namespace std;

int Product::uniqueId = 0;

void Product::Read(std::istream& istream, std::ostream& ostream)
{
	ostream << "Enter Name: ";
	getline(istream, name);
}

void Product::Write(std::ostream& ostream)
{
	ostream << "Id: " << id << endl;
	ostream << "Name: " << name << endl;
}

void Product::Read(std::ifstream& istream)
{
	istream >> id;
	istream.ignore(80, '\n');
	getline(istream, name);
}

void Product::Write(std::ofstream& ostream)
{
	ostream << id << endl;
	ostream << name << endl;
}
