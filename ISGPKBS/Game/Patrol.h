#pragma once

#include "Animation.h"
#include "IBehaviour.h"
#include "IPaintable.h"
#include "Grid.h"
#include "Entity.h"
#include "Player.h"

namespace isgp {
	// A simple enemy that walks to the left and right.
	class Patrol : public Entity {
	public:
		Patrol(Vector2D, int, Player*);
		~Patrol();
		void Update(const double) override;
		void Paint(Graphics* g) override;
	private:
		Vector2D _startingPoint;
		int _range;
		const int _movement_speed;
		Animation* _animation;
		Player* _player;
		bool _facingRight;
		void AddToVelocityY(double) override;
		Vector2D _oldPosition;
	};
}
