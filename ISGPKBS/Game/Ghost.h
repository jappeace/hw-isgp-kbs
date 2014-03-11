#pragma once

#include "Enemy.h"

namespace isgp {
	class Ghost : public Enemy
	{
	public:
		Ghost(Vector2D, Player*);
		void Update(double) override;
	};
}

