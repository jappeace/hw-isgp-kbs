#include "Level.h"
#include "GridGraphicTranslator.h"
namespace isgp{
const Size	Level::tileSize = Size(TILE_WIDTH, TILE_HEIGHT);
	Level::Level(int width, int height) {
		_grid = new Grid(width, height);
	}
	Level::Level(Grid* grid) {
		_grid = grid;
		_player = new Player(Point(100,100));
		_player->SetGrid(_grid);
	}

	Level::~Level(void)
	{
		if(_grid){
			delete _grid;
		}
	}
	void Level::Paint(Graphics* g) {
		_graphics = g;
		_grid->TraverseTiles(this);
		_player->Paint(g);

	}
	void Level::ReceiveTile(Tile* tile) {
#ifdef _DEBUG
		Point position = *tile->GetPosition();
		position.SetX(position.GetX() * Level::tileSize.GetWidth());
		position.SetY(position.GetY() * Level::tileSize.GetHeight());

		_graphics->DrawRect(
			position, 
			Point(
				position.GetX() + Level::tileSize.GetWidth(),
				position.GetY() + Level::tileSize.GetHeight()
			)
		);
#endif
		tile->Paint(_graphics);
	}
}
