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

	
	int Entity::Collides(double x, double y) {
		_position += Vector2D(x, y);
		collision = CheckCollision();
		_position -= Vector2D(x, y);
		return collision;
	}

	void Entity::Move(Vector2D velocity) {
		if(velocity.X() != 0 || velocity.Y() != 0) {
			double allowedX = 0;
			double allowedY = 0;

			while(true) {
				double stepSizeX = CalcStepSize(velocity.X() - allowedX);
				double stepSizeY = CalcStepSize(velocity.Y() - allowedY);

				int xCollision = Collides(allowedX + stepSizeX, 0);
				int yCollision = Collides(0, allowedY + stepSizeY);

				bool canMoveX = stepSizeX != 0;
				bool canMoveY = stepSizeY != 0;

				if(((xCollision & Left) && velocity.X() < 0) || ((xCollision & Right) && velocity.X() > 0)) {
					canMoveX = false;
				}

				if(((yCollision & Up) && velocity.Y() < 0) || ((yCollision & Down) && velocity.Y() > 0)) {
					canMoveY = false;
				}

				
				if(canMoveX) {
					allowedX += stepSizeX;
				}

				if(canMoveY) {
					allowedY += stepSizeY;
				}

				if(!canMoveX && !canMoveY) {
					break;
				}
			}

			if(allowedX != 0.0 || allowedY != 0.0) {
				_position += Vector2D(allowedX, allowedY);
				if(allowedY != 0) {
					_position += Vector2D(0, velocity.Y() < 0 ? -1 : 1);
				}
				if(allowedX != 0) {
					_position += Vector2D(velocity.X() < 0 ? -1 : 1, 0);
				}
			}
			
		}
		
	}

	double Entity::CalcStepSize(double vel) {
		/*if(abs(vel) < 0.1) {
			return 0.0;
		} else {
			*/return (vel > 0) ? min(vel, 1) : max(vel, -1);
		//}
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