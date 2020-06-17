#pragma once
#include "product.h"

class Movie : public Product
{
public:
	Movie() {}

	eType GetType() override { return eType::MOVIE; }

protected:
	int time;
};

