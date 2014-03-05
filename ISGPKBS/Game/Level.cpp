#include "Level.h"
#include "GridGraphicTranslator.h"
namespace isgp{
// default amount of tiles in level
const Size Level::defaultTileAmount = Size(50,100);

// tile size, should equal the width and height of spritesheet tiles
const Size	Level::tileSize = Size(TILE_WIDTH, TILE_HEIGHT);
	Level::Level(){
		init(new Grid(defaultTileAmount.GetWidth(), defaultTileAmount.GetHeight()));
	}
	Level::Level(int width, int height){
		init(new Grid(width, height));
	}
	Level::Level(Grid* grid) {
		init(grid);
	}
	void Level::init(Grid* grid){
		_grid = grid;
		_player = new Player(Point(1,1));
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
	Grid* Level::GetGrid() const{
		return _grid;
	}
}
