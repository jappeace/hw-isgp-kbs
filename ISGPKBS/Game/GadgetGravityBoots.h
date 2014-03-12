#pragma once

#include "Entity.h"

namespace isgp {

	class GadgetGravityBoots : public Entity
	{
	public:
		GadgetGravityBoots(void);
		~GadgetGravityBoots(void);

		void Paint(Graphics* g);
		void Update(const double);
	};
}
