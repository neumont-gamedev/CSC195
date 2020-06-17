#pragma once
#include "shape.h"

class Box :	public Shape
{
public:
	virtual bool Update(float dt) override;
	virtual void Draw(Core::Graphics& graphics) override;
	virtual eType Type() override { return eType::BOX; }
};

