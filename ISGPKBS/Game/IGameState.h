#pragma once

#include "IPaintable.h"
#include "IKeyHandler.h"

namespace isgp {
	class IGameState : public IPaintable, public IKeyHandler {
	public:
		virtual ~IGameState() {}
		virtual void Update(double elapsed) = 0;
	};
}
