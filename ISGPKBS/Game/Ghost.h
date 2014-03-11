#pragma once

#include "Enemy.h"

namespace isgp {
	class Ghost : public Enemy
	{
	public:
		Ghost(Point, Player*);
		void Update(double) override;
	};
}

