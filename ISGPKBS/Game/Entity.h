#pragma once
#include "IPaintable.h"
#include "Vector2D.h"
#include "Point.h"
#include "Graphics.h"
namespace isgp {
class Entity : public IPaintable
{
public:
	virtual void Paint(Graphics* g) override = 0;
	virtual void Update() = 0;
	Point _position;

protected:
	Vector2D _velocity;
};
}

