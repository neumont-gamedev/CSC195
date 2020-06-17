#include "painter.h"
#include "MathLib.h"

Painter::~Painter()
{
	for (Shape* shape : m_shapes)
	{
		delete shape;
	}

	m_shapes.clear();
}

void Painter::Update(float dt)
{
	if (m_shape == nullptr && Core::Input::IsPressed(Core::Input::BUTTON_LEFT))
	{
		m_shape = Shape::CreateShape(m_shapeType);
	}

	if (m_shape)
	{
		bool place = m_shape->Update(dt);
		if (place)
		{
			m_shapes.push_back(m_shape);
			m_shape = nullptr;
		}
	}
}

void Painter::Draw(Core::Graphics& graphics)
{
	// current shape
	if (m_shape)
	{
		m_shape->Draw(graphics);
	}

	// all shapes
	for (Shape* shape : m_shapes)
	{
		shape->Draw(graphics);
	}
}

void Painter::Load(const std::string& filename)
{
}

void Painter::Save(const std::string& filename)
{
}
