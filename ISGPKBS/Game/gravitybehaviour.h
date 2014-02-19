#pragma once

#include "behaviourinterface.h"

namespace isgp {

	// Gravity Behaviour is a child of "BehaviourInterface".
	// The Gravity Behaviour will force the object to be pulled downward by gravity.
	class GravityBehaviour : public BehaviourInterface
	{
	public:
		GravityBehaviour(void);
		~GravityBehaviour(void);

		void Update(const long ms);
	};
}
