#include "Entity.h"
#include "GridGraphicTranslator.h"
namespace isgp {

	void Entity::SetGrid(Grid* grid) {
		this->_grid = grid;
	}

	int Entity::CheckCollision(Point topLeft, Point bottomRight) {
		if(!_grid) {
			return None;
		}
		CollidingTiles.clear();
		int collision = 0;
		vector<Tile*> includedTiles = _grid->GetTilesInRectangle(topLeft, bottomRight);
		GridGraphicTranslator translator = GridGraphicTranslator();
		const double diffWidth = TILE_WIDTH / 2;
		const double diffHeight =  TILE_HEIGHT / 2;
		for(unsigned i = 0; i < includedTiles.size(); i++) {
			Tile* currentTile = includedTiles.at(i);
			if(currentTile->HasData() ) {
				Point absoluteTilePositionTL = translator.FromTo(*currentTile->GetPosition());

				Point tileCenter = Point(absoluteTilePositionTL.GetX() + diffWidth, absoluteTilePositionTL.GetY() + diffHeight);

				double diffX = topLeft.GetX() - tileCenter.GetX();
				if(abs(diffX) < diffWidth){
					collision |= Left;
				}
				diffX = bottomRight.GetX() - tileCenter.GetX();
				if(abs(diffX) < diffWidth){
					collision |= Right;
				}

				double diffY = topLeft.GetY() - tileCenter.GetY();
				if(abs(diffY) < diffHeight){
					collision |= Up;
				}
				diffY = bottomRight.GetY() - tileCenter.GetY();
				if(abs(diffY) < diffHeight){
					collision |= Down;
				}
				if(collision != None) {
					CollidingTiles.push_back(currentTile);

				}
				//TopLeft bottomRight = player 
				
				
			}
		}

		return collision;
	}
}