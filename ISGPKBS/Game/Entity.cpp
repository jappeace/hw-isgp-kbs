#include "Entity.h"
#include "GridGraphicTranslator.h"
#include "CollisionDetection.h"

namespace isgp {

	void Entity::SetGrid(Grid* grid) {
		this->_grid = grid;
	}

	void Entity::SetSize(Vector2D* size) {
		_size = size;
	}

	int Entity::GetCollision() const {
		return collision;
	}

	Vector2D* Entity::GetVelocity() const {
		return _velocity;
	}

	Vector2D* Entity::GetSize() const {
		return _size;
	}

	int Entity::CheckCollision() {
		if(!_grid) {
			return None;
		}
		CollidingTiles.clear();
		collision = None;
		Vector2D bottomRight = this->_position + *_size + Vector2D(2);
		Vector2D topLeft = this->_position - Vector2D(2);
		vector<Tile*> includedTiles = _grid->GetTilesInRectangle(this->_position, bottomRight);
		GridGraphicTranslator translator = GridGraphicTranslator();
		Vector2D diff = Vector2D(TILE_WIDTH / 2, TILE_HEIGHT / 2);

		for(unsigned i = 0; i < includedTiles.size(); i++) {
			Tile* currentTile = includedTiles.at(i);
			if(currentTile->GetData()) {
				Vector2D absoluteTilePositionTL = translator.FromTo(*currentTile->GetPosition());
				Vector2D tileCenter = absoluteTilePositionTL + diff;
			
				if(abs(absoluteTilePositionTL.Y() - topLeft.Y()) < _size->Y()){
					double diffX = topLeft.X() - tileCenter.X();
					if(abs(diffX) < diff.X()){
						collision |= Left;
					}
					
					diffX = bottomRight.X() - tileCenter.X();
					if(abs(diffX) < diff.X()){
						collision |= Right;
					}
					
				}
				if(abs(absoluteTilePositionTL.X() - topLeft.X()) < _size->X()){
					double diffY = topLeft.Y() - tileCenter.Y();
					if(abs(diffY) < diff.Y()){
						collision |= Up;
					}
					diffY = bottomRight.Y() - tileCenter.Y();
					if(abs(diffY) < diff.Y()){
						collision |= Down;
					}
				}




				if(collision != None) {
					CollidingTiles.push_back(currentTile);
				}
				
				
			}
		}

		return collision;
	}
}