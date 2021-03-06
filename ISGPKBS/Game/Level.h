#pragma once

#include "Grid.h"
#include "IPaintable.h"
#include "Player.h"
#include "Ghost.h"
#include "Patrol.h"
#include "Gadget.h"
#include "Theme.h"
#include "Finish.h"
#include "TimeFormatter.h"

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
		Finish* finish;
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
		double GetPlayTime();
		int GetStageNumber();
		void SetStageNumber(int nr);
	private:
		void Init();
		double _timePlayed;
		Grid* _grid;
		int _stagenr;
	};
}
