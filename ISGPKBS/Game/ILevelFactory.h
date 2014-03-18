#pragma once
#include "Level.h"
namespace isgp{

	class ILevelFactory{
	public:
		virtual Level* CreateLevel(int level) = 0;
	};

}