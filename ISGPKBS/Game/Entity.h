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
	Entity();
	virtual void Paint(Graphics* g) override = 0;
	virtual void Update(const double) = 0;
	Vector2D _position;
	void SetGrid(Grid* grid);
	vector<Tile*> CollidingTiles;
	Vector2D* GetSize() const;
	void SetSize(Vector2D* size);
	int GetCollision() const;
	Vector2D* GetVelocity() const;
	virtual void AddToVelocityY(double);
	void Move(Vector2D);

protected:
	double CalcStepSize(double vel);
	int Collides(double x, double y);

	int collision;
	Grid* _grid;
	Vector2D* _size;
	Vector2D* _velocity;

private:
	int CheckCollision();
};
}

