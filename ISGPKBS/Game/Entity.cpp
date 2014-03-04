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
		for(unsigned i = 0; i < includedTiles.size(); i++) {
			Tile* currentTile = includedTiles.at(i);
			if(currentTile->HasData() && currentTile->GetData()->IsSolid) {
				Point absoluteTilePosition = translator.FromTo(*currentTile->GetPosition());
				
				//TopLeft bottomRight = player 
				//absoluteTilePosition = tile, + tile width & height = boundaries

				    double pL = topLeft.GetX(),             //left
						   pR = bottomRight.GetX(),    //right
						   pT = topLeft.GetY(),             //top
						   pB = bottomRight.GetY();   //bottom

					double tL = absoluteTilePosition.GetX(),               //left
						   tR = tL + TILE_WIDTH,      //right
						   tT = absoluteTilePosition.GetY(),               //top
						   tB = tT + TILE_HEIGHT;     //bottom

					if(pR > tL && pL < tL) {             // Player on left
						collision |= Left;
						CollidingTiles.push_back(currentTile);
					}
					if(pL < tR && pR > tR) {            // Player on Right
						collision |= Right;
						CollidingTiles.push_back(currentTile);
					}
					if(pT < tT && pT > tB){
						collision |= Down;
						CollidingTiles.push_back(currentTile);
					}
					if(pT > tT && pB < tT) {            // Player on Bottom
						
					}
					if(pB < tB && pT > tB) {            // Player on Top
						collision |= Up;
						CollidingTiles.push_back(currentTile);
					}
			}
		}

		return collision;
	}
}