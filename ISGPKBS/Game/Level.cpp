#include "Level.h"

namespace isgp{

	Level::Level(int width, int height){
		_grid = new Grid(width, height);
	}
	Level::Level(Grid* grid)
	{
		_grid = grid;
	}

	Level::~Level(void)
	{
		if(_grid){
			delete _grid;
		}
	}
	void Level::paint(Graphics* g){
		_graphics = g;
		_grid->traverseTiles(this);
	}
	void Level::receiveTile(Tile* tile){
#ifdef _DEBUG
		Point position = *tile->GetPosition();
		position.SetX(position.GetX() * _tileSize->GetWidth());
		position.SetY(position.GetY() * _tileSize->GetHeight());

		_graphics->drawRect(
			position, 
			Point(
				position.GetX() + _tileSize->GetWidth(),
				position.GetY() + _tileSize->GetHeight()
			)
		);
#endif
	}
	void Level::setTileSize(Size* s){
		_tileSize = s;
	}
	
    Size* Level::getSize() const{
		return _grid->getSize();
	}
}