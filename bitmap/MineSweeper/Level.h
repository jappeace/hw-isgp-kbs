#pragma once
#include "Grid.h"
namespace isgp{

	class Level
	{
	public:
		Level(Grid* grid);
		Level(int width, int height);
		~Level(void);
	private:
		Grid* _grid;
	};

}