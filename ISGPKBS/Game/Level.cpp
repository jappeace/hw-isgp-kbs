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
		_player = new Player(Point(100,100));
		_enemy = new Ghost(Point(100,100), _player);
		_enemy2 = new Patrol(Point(500,221), 100, _player);
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
		_enemy->Paint(g);
		_enemy2->Paint(g);
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
	Grid* Level::GetGrid() const{
		return _grid;
	}
}
