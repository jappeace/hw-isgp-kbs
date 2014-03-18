#include "Level.h"
#include "GridGraphicTranslator.h"
#include "Camera.h"
namespace isgp{
// default amount of tiles in level
const Size Level::defaultTileAmount = Size(500,30);

// tile size, should equal the width and height of spritesheet tiles
const Size	Level::tileSize = Size(TILE_WIDTH, TILE_HEIGHT);
	Level::Level(){
		start = NULL;
		finish = NULL;
		_player = NULL;
		_grid = new Grid(defaultTileAmount.GetWidth(), defaultTileAmount.GetHeight());
	}
	Level::Level(int width, int height) {
		start = NULL;
		finish = NULL;
		_player = NULL;
		_grid = new Grid(width, height);
	}
	Level::Level(Grid* grid) {
		start = NULL;
		finish = NULL;
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

		double collisionRange = sqrt(pow(finish.X() - _player->GetPosition().X(), 2) + pow(finish.Y() - _player->GetPosition().Y(), 2));
		if (collisionRange < 26) {
			//player finished
		}

		// Update enemies.
		for (auto it = entities.begin(); it != entities.end(); ++it) {
			(*it)->Update(elapsed);
		}
	}

	void Level::Paint(Graphics* g) {
		_player->Paint(g);
		// Update entities.
		for (auto it = entities.begin(); it != entities.end(); ++it) {
			(*it)->Paint(g);
		}
	}
	Grid* Level::GetGrid() const{
		return _grid;
	}
}
