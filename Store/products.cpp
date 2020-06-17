#include "products.h"
#include "movie.h"
#include <fstream>
#include <assert.h>

using namespace std;

Products::~Products()
{
}

void Products::Load(const std::string& filename)
{
	ifstream file(filename);
	if (file.is_open())
	{
		while (!file.eof())
		{
			int type;
			file >> type;

			if (file.eof()) break;

			Product* product = Create(static_cast<Product::eType>(type));
			assert(product);

			product->Read(file);
			products.push_back(product);
		}

		file.close();
	}
}

void Products::Save(const std::string& filename)
{
	ofstream file(filename);
	if (file.is_open())
	{
		for (Product* product : products)
		{
			file << static_cast<int>(product->GetType()) << std::endl;
			product->Write(file);
		}

		file.close();
	}
}

void Products::Display()
{
	for (Product* product : products)
	{
		product->Write(std::cout);
	}
}

void Products::Display(Product::eType type)
{
	for (Product* product : products)
	{
		if (product->GetType() == type)
		{
			product->Write(std::cout);
		}
	}
}

void Products::Display(int id)
{
	for (Product* product : products)
	{
		if (product->GetId() == id)
		{
			product->Write(std::cout);
		}
	}
}

Product* Products::Create(Product::eType type)
{
	Product* product = nullptr;

	switch (type)
	{
	case Product::eType::MOVIE:
		product = new Movie;
		break;
	case Product::eType::ALBUM:
		//product = new Album;
		break;
	case Product::eType::BOOK:
		//product = new Book;
		break;
	default:
		break;
	}

	return product;
}

void Products::Add(Product* product)
{
	products.push_back(product);
}

void Products::Remove()
{
	for (Product* product : products)
	{
		delete product;
	}

	products.clear();
}

void Products::Remove(int id)
{
	for (auto iter = products.begin(); iter != products.end(); iter++)
	{
		if ((*iter)->GetId() == id)
		{
			delete *iter;
			iter = products.erase(iter);
		}
	}
}
