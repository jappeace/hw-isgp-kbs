#pragma once

#include "Grid.h"
#include "IPaintable.h"
#include "Player.h"
#include "Ghost.h"
#include "Patrol.h"
#include "Gadget.h"
namespace isgp{
	// represents a level in the game
	class Level : public IPaintable, public IGridTraveller {
	public:
		Level();
		Level(Grid* grid);
		Level(int width, int height);
		~Level(void);
		Vector2D *start;
		Vector2D *finish;
		void ReceiveTile(Tile* tile) override;
		void Paint(Graphics* g) override;
		static const Size tileSize;
		Player* _player;
		vector<Entity*> enemies;
		vector<Gadget*> gadgets;
		Entity* _enemy;
		Entity* _enemy2;
		Gadget* _gadget;
		Gadget* _gadget2;
		Grid* GetGrid() const;
		static const Size defaultTileAmount;
	private:
		Graphics* _graphics; // bridge between paint and receive tile
		Grid* _grid;
	};
}
