#pragma once
#include "CollisionDetection.h"
#include "Graphics.h"
#include "Grid.h"
#include "IPaintable.h"
#include "Size.h"
#include "Vector2D.h"
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
	// Check if the entity is colliding on the given side
	bool IsColliding(Collision collisionSide);

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

