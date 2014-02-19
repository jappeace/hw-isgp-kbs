#pragma once
#include "Grid.h"
#include "IPaintable.h"
namespace isgp{

	// represents a level in the game
	class Level : IPaintable, IGridTraveller
	{
	public:
		Level(Grid* grid);
		Level(int width, int height);
		~Level(void);
		void ReceiveTile(Tile* tile);
		void Paint(Graphics* g);
		static const Size tileSize;
	private:
		Graphics* _graphics; // bridge between paint and receive tile
		Grid* _grid;
	};

}