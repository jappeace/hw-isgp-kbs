#pragma once

#include "IPaintable.h"

namespace isgp {
	class IGameState : public IPaintable {
	public:
		virtual void Paint(Graphics* g) = 0;
		virtual void Update(double elapsed) = 0;
	};
}
