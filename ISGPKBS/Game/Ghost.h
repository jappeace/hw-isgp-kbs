#pragma once

#include "Entity.h"
#include "Player.h"

namespace isgp {
	class Ghost : public Entity
	{
	public:
		Ghost(Vector2D, Player*);
		~Ghost();
		void Update(const double) override;
		void Paint(Graphics*) override;
		void AddToVelocityY(double) override;
	private:
		// If the player is facing right
		bool _facingRight;
		Graphics* _graphics;
		double _aVel;
		Player* _player;
		double _radAngle;
	};
}

