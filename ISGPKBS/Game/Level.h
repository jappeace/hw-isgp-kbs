#pragma once

#include "Grid.h"
#include "IPaintable.h"
#include "Player.h"

namespace isgp{
	// represents a level in the game
	class Level : public IPaintable, public IGridTraveller {
	public:
		Level();
		Level(Grid* grid);
		Level(int width, int height);
		~Level(void);
		void ReceiveTile(Tile* tile) override;
		void Paint(Graphics* g) override;
		static const Size tileSize;
		Player* _player;
	private:
		Graphics* _graphics; // bridge between paint and receive tile
		Grid* _grid;
	};
}
