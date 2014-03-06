#pragma once
#include "IPaintable.h"
#include "Vector2D.h"
#include "Point.h"
#include "Graphics.h"
#include <vector>
#include "Tile.h"
#include "GridGraphicTranslator.h"
#include "Grid.h"
namespace isgp {

class Entity : public IPaintable
{
public:
	virtual void Paint(Graphics* g) override = 0;
	virtual void Update(const double) = 0;
	int CheckCollision(Point topLeft, Point bottomRight);
	Point _position;
	int collision;
	void SetGrid(Grid* grid);
	vector<Tile*> CollidingTiles;

protected:
	Vector2D _velocity;
	Grid* _grid;

public:
	enum Collision {
		None = 0,
		Left = 1,
		Up = 2,
		Right = 4,
		Down = 8
	};
};
}

