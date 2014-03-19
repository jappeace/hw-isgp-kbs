#pragma once

#include "Grid.h"
#include "IPaintable.h"
#include "Player.h"
#include "Ghost.h"
#include "Patrol.h"
#include "Gadget.h"
#include "Theme.h"
namespace isgp{
	class Theme;
	// represents a level in the game
	class Level : public IPaintable{
	public:
		Level();
		Level(Grid* grid);
		Level(int width, int height);
		~Level(void);
		Vector2D *start;
		Vector2D finish;
		bool IsFinished();
		void Paint(Graphics* g) override;
		void Update(double elapsed);
		static const Size tileSize;
		Player* _player;
		vector<Entity*> entities;
		Grid* GetGrid() const;
		static const Size defaultTileAmount;
		Theme* _theme;
		void LoadContent(Graphics*);
	private:
		Grid* _grid;
	};
}
