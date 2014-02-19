#pragma once
#include "Grid.h"
#include "IPaintable.h"
namespace isgp{

	class Level : IPaintable, IGridTraveller
	{
	public:
		Level(Grid* grid);
		Level(int width, int height);
		~Level(void);
		void receiveTile(Tile* tile);
		void paint(Graphics* g);
		static const Size tileSize;
	private:
		Graphics* _graphics; // bridge between paint and receive tile
		Grid* _grid;
	};

}