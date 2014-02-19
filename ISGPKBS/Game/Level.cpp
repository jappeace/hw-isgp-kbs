#include "Level.h"

namespace isgp{
const Size	Level::tileSize = Size(TILE_WIDTH, TILE_HEIGHT);
	Level::Level(int width, int height) {
		_grid = new Grid(width, height);
	}
	Level::Level(Grid* grid) {
		_grid = grid;
	}

	Level::~Level(void)
	{
		if(_grid){
			delete _grid;
		}
	}
	void Level::paint(Graphics* g) {
		_graphics = g;
		_grid->traverseTiles(this);
	}
	void Level::receiveTile(Tile* tile) {
#ifdef _DEBUG
		Point position = *tile->GetPosition();
		position.SetX(position.GetX() * Level::tileSize.GetWidth());
		position.SetY(position.GetY() * Level::tileSize.GetHeight());

		_graphics->drawRect(
			position, 
			Point(
				position.GetX() + Level::tileSize.GetWidth(),
				position.GetY() + Level::tileSize.GetHeight()
			)
		);
#endif
		tile->paint(_graphics);
	}
}
