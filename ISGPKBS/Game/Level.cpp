#include "Camera.h"
#include "CollisionHelper.h"
#include "GridGraphicTranslator.h"
#include "Level.h"

namespace isgp{
// default amount of tiles in level
const Size Level::defaultTileAmount = Size(500,30);

// tile size, should equal the width and height of spritesheet tiles
const Size	Level::tileSize = Size(TILE_WIDTH, TILE_HEIGHT);
	Level::Level(){
		start = NULL;
		_player = NULL;
		_grid = new Grid(defaultTileAmount.GetWidth(), defaultTileAmount.GetHeight());
	}
	Level::Level(int width, int height) {
		start = NULL;
		_player = NULL;
		_grid = new Grid(width, height);
	}
	Level::Level(Grid* grid) {
		start = NULL;
		_player = NULL;
		_grid = grid;
	}

	Level::~Level(void)
	{
		delete _grid;
		delete start;
		delete _player;
		for (auto it = entities.begin(); it != entities.end(); ++it) {
			delete (*it);
		}
	}

	void Level::Update(double elapsed) {
		// Update player
		_player->Update(elapsed);
		finish->Update(elapsed);
		// Update enemies.
		for (auto it = entities.begin(); it != entities.end(); ++it) {
			(*it)->Update(elapsed);
		}
	}

	void Level::LoadContent(Graphics* g) {
		_theme->LoadContent(g);
	}

	void Level::Paint(Graphics* g) {
		_theme->Paint(g);
		finish->Paint(g);
		_player->Paint(g);
		// Update entities.
		for (auto it = entities.begin(); it != entities.end(); ++it) {
			(*it)->Paint(g);
		}
	}

	bool Level::IsFinished() {
		return CollisionHelper::IsColliding(_player->GetPosition(), *_player->GetSize(), finish->GetPosition(), Size(16, 16));
	}

	Grid* Level::GetGrid() const{
		return _grid;
	}
}
