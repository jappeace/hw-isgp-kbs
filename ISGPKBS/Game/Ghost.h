#pragma once

#include "Entity.h"
#include "Player.h"

namespace isgp {
	class Ghost : public Entity
	{
	public:
		Ghost(Vector2D, Player*);
		void Update(const double) override;
		void Paint(Graphics*) override;
		void AddToVelocityY(double) override;
	private:
		// If the player is facing right
		bool _facingRight;
		Graphics* _graphics;
		vector<IBehaviour*>* _behaviours;
		double _aVel;
		Player* _player;
		double _radAngle;
	};
}

