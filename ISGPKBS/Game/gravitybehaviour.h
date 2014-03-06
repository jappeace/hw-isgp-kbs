#pragma once

#include "IBehaviour.h"
namespace isgp {
	class Player;

	// Gravity Behaviour is a child of "BehaviourInterface".
	// The Gravity Behaviour will force the object to be pulled downward by gravity.
	class GravityBehaviour : public IBehaviour
	{
	public:
		GravityBehaviour(Player* player);
		~GravityBehaviour(void);

		void Update(const double ms);

	private:
		Player* _player;
	};
}
