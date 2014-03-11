#pragma once

#include "Enemy.h"

namespace isgp {
	class Ghost : public Enemy
	{
	public:
		Ghost(Point, Player*);
		void Update(double) override;
		void Paint(Graphics* g) override;
	private:
		// If the player is facing right
		bool _facingRight;
		Graphics* _graphics;
	};
}

