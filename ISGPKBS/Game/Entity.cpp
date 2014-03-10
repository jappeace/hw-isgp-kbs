#include "Entity.h"
#include "GridGraphicTranslator.h"
namespace isgp {

	void Entity::SetGrid(Grid* grid) {
		this->_grid = grid;
	}

	int Entity::CheckCollision(Vector2D topLeft, Vector2D bottomRight) {
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
				Vector2D absoluteTilePositionTL = translator.FromTo(*currentTile->GetPosition());

				Vector2D tileCenter = Vector2D(absoluteTilePositionTL.X() + diffWidth, absoluteTilePositionTL.Y() + diffHeight);

				double diffX = topLeft.X() - tileCenter.X();
				if(abs(diffX) < diffWidth){
					collision |= Left;
				}
				diffX = bottomRight.X() - tileCenter.X();
				if(abs(diffX) < diffWidth){
					collision |= Right;
				}

				double diffY = topLeft.Y() - tileCenter.Y();
				if(abs(diffY) < diffHeight){
					collision |= Up;
				}
				diffY = bottomRight.Y() - tileCenter.Y();
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