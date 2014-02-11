#include "Level.h"

namespace isgp{

	Level::Level(int width, int height){
		_grid = new Grid(width, height);
	}
	Level::Level(Grid* grid)
	{
		_grid = grid;
	}

	Level::~Level(void)
	{
		delete _grid;
	}

}