#pragma once
#include "Level.h"
namespace isgp{

	class ILevelFactory{
	public:
		virtual Level CreateLevel() = 0;
	};

}