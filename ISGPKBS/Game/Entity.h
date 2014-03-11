#pragma once
#include "IPaintable.h"
#include "Vector2D.h"
#include "Graphics.h"
#include "Grid.h"
#include "Size.h"
namespace isgp {
class Entity : public IPaintable
{
public:
	virtual void Paint(Graphics* g) override = 0;
	virtual void Update(const double) = 0;
	int CheckCollision();
	Vector2D _position;
	void SetGrid(Grid* grid);
	vector<Tile*> CollidingTiles;
	Vector2D* GetSize() const;
	void SetSize(Vector2D* size);
	int GetCollision() const;

protected:
	int collision;
	Grid* _grid;
	Vector2D* _size;
};
}

