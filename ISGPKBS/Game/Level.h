#pragma once

#include "Grid.h"
#include "IPaintable.h"
#include "Player.h"
#include "Ghost.h"
#include "Patrol.h"

namespace isgp{
	// represents a level in the game
	class Level : public IPaintable{
	public:
		Level();
		Level(Grid* grid);
		Level(int width, int height);
		~Level(void);
		void Paint(Graphics* g) override;
		static const Size tileSize;
		Player* _player;
		Entity* _enemy;
		Entity* _enemy2;
		Grid* GetGrid() const;
		static const Size defaultTileAmount;
	private:
		Grid* _grid;
	};
}
