#pragma once
#include "Level.h"
namespace isgp{

	class ILevelFactory{
	public:
		virtual Level* CreateLevel(int level, Theme*) = 0;
		virtual bool LevelExists(int level) = 0;
	};

}