#pragma once
#include "CollisionDetection.h"
#include "Graphics.h"
#include "Grid.h"
#include "IBehaviour.h"
#include "IPaintable.h"
#include "Size.h"
#include "Vector2D.h"
namespace isgp {
class Entity : public IPaintable
{
public:
	Entity();
	// Paints the entity onto the graphics context
	virtual void Paint(Graphics* g) override = 0;
	// Update the entity state
	virtual void Update(const double) = 0;
	// Adds a given value to the velocity
	virtual void AddToVelocityY(double);

	// Moves the entity with the given velocity.
	// Collision detection will apply to this movement.
	void Move(Vector2D);
	// Adds a behaviour to the entity
	void AddBehaviour(IBehaviour*);
	// Removes a behaviour from the entity
	void RemoveBehaviour(IBehaviour*);
	// Check if the entity is colliding on the given side
	bool IsColliding(Collision collisionSide);
	// Sets the grid for collision detection
	void SetGrid(Grid* grid);
	// Sets the size of this entity for collision detection
	void SetSize(Vector2D* size);
	// Gets the size of this entity
	Vector2D* GetSize() const;
	// Gets the current collision state of this entity
	int GetCollision() const;
	// Gets the velocity of this entity
	Vector2D* GetVelocity() const;
	// Gets the position of this entity
	Vector2D GetPosition() const;

protected:
	// The current collision state
	int collision;
	// The grid used in collision detection
	Grid* _grid;
	// The size of the entity
	Vector2D* _size;
	// The velocity of the entity
	Vector2D* _velocity;
	// The position of the entity
	Vector2D _position;
	// The tiles with which the entity is colliding
	vector<Tile*> CollidingTiles;
	// The behaviours of this entity
	vector<IBehaviour*>* _behaviours;
	
	// Checks the collisions for the the current entity state
	int CheckCollision();
private:
	

	// Creates a movement step size which returns 0 or 0.5
	double CalcStepSize(double vel);
	// Checks the collision state if the given values would be added to the entity.
	int Collides(double x, double y);
};
}

