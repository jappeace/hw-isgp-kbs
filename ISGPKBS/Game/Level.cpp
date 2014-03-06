#include "Level.h"
#include "GridGraphicTranslator.h"
namespace isgp{
// default amount of tiles in level
const Size Level::defaultTileAmount = Size(10,10);

// tile size, should equal the width and height of spritesheet tiles
const Size	Level::tileSize = Size(TILE_WIDTH, TILE_HEIGHT);
	Level::Level(){
		_grid = new Grid(defaultTileAmount.GetWidth(), defaultTileAmount.GetHeight());
	}
	Level::Level(int width, int height) {
		_grid = new Grid(width, height);
	}
	Level::Level(Grid* grid) {
		_grid = grid;
		_player = new Player(Vector2D(100,100));
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
		Vector2D position = *tile->GetPosition();
		position.X(position.X() * Level::tileSize.GetWidth());
		position.Y(position.Y() * Level::tileSize.GetHeight());

		_graphics->DrawRect(
			position, 
			Vector2D(
				position.X() + Level::tileSize.GetWidth(),
				position.Y() + Level::tileSize.GetHeight()
			)
		);
#endif
		tile->Paint(_graphics);
	}
	Grid* Level::GetGrid() const{
		return _grid;
	}
}
