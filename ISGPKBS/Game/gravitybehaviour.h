#pragma once

#include "IBehaviour.h"
#include "Entity.h"

namespace isgp {

	// Gravity Behaviour is a child of "BehaviourInterface".
	// The Gravity Behaviour will force the object to be pulled downward by gravity.
	class GravityBehaviour : public IBehaviour
	{
	public:
		static double CalculateGravity(const double);
		GravityBehaviour(Entity* entity);
		~GravityBehaviour(void);

		void Update(const double ms);

	private:
		Entity* _entity;
	};
}
