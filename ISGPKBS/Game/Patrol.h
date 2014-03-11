#pragma once

#include "Enemy.h"

namespace isgp {
	class Patrol : public Enemy
	{
	public:
		Patrol(Vector2D, int, Player*);
		void Update(double) override;
	private:
		Vector2D _startingPoint;
		int _range;
	};
}
