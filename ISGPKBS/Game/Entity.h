#pragma once
#include "IPaintable.h"
#include "Vector2D.h"
#include "Graphics.h"
#include "Grid.h"
namespace isgp {
class Entity : public IPaintable
{
public:
	virtual void Paint(Graphics* g) override = 0;
	virtual void Update(const double) = 0;
	int CheckCollision(Vector2D topLeft, Vector2D bottomRight);
	Vector2D _position;
	int collision;
	void SetGrid(Grid* grid);
	vector<Tile*> CollidingTiles;

protected:
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

