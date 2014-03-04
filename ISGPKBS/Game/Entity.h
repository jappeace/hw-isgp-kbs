#pragma once
#include "IPaintable.h"
#include "Vector2D.h"
#include "Point.h"
#include "Graphics.h"
#include "Grid.h"
namespace isgp {
class Entity : public IPaintable
{
public:
	virtual void Paint(Graphics* g) override = 0;
	virtual void Update() = 0;
	int CheckCollision(Point topLeft, Point bottomRight);
	Point _position;
	void SetGrid(Grid* grid);
	vector<Tile*> CollidingTiles;

protected:
	Vector2D _velocity;
	Grid* _grid;

	enum Collision {
		None = 0,
		Left = 1,
		Up = 2,
		Right = 4,
		Down = 8
	};
};
}

