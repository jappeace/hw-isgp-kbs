#include "Entity.h"
#include "GridGraphicTranslator.h"
#include "PlayingGameState.h"
namespace isgp {

	Entity::Entity() {
		this->collision = None;
	}

	void Entity::SetGrid(Grid* grid) {
		this->_grid = grid;
	}

	void Entity::SetSize(Vector2D* size) {
		_size = size;
	}

	int Entity::GetCollision() const {
		return collision;
	}

	Vector2D Entity::GetPosition() const {
		return _position;
	}

	Vector2D* Entity::GetVelocity() const {
		return _velocity;
	}

	Vector2D* Entity::GetSize() const {
		return _size;
	}

	void Entity::AddBehaviour(IBehaviour* behaviour) {
		_behaviours->push_back(behaviour);
	}

	void Entity::RemoveBehaviour(IBehaviour* behaviour) {
		for (unsigned int i = 0; i < _behaviours->size(); ++i) {
			if(_behaviours->at(i) == behaviour) {
				_behaviours->erase(_behaviours->begin() + i);
			}
		}
	}
	
	int Entity::Collides(double x, double y) {
		_position += Vector2D(x, y);

		int collision = None;
		GridGraphicTranslator ggt;
		Vector2D maxPos = ggt.FromTo(Vector2D((int) _grid->GetSize()->GetWidth(), (int) _grid->GetSize()->GetHeight()));
		if (_position.X() <= 0) {
			collision = Left;
		} else if (_position.X() + (GetSize()->X() * 1.25) >= maxPos.X()) {
			collision = Right;
		}
		if (_position.Y() <= 0) {
			collision = Up;
		} else if (_position.Y() + (GetSize()->Y() * 1.25) >= maxPos.Y()) {
			collision = Down;
		} 

		if (collision == None) {
			collision = CheckCollision();
		}

		_position -= Vector2D(x, y);
		return collision;
	}

	void Entity::Move(Vector2D velocity) {
		if(!(velocity.X() != 0.0 || velocity.Y() != 0.0)) {
			return;
		}

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

		double x = velocity.X() < 0 ? -.5 : .5;
		double y = velocity.Y() < 0 ? -.5 : .5;

		if(allowedX != 0.0 || allowedY != 0.0) {
			_position += Vector2D(allowedX, allowedY);
		}

		int xCol = Collides(x, 0);
		int yCol = Collides(0, y);

if(PlayingGameState::_debugMode)
{
		Collides(x, y);
}

		collision = (xCol & (Left | Right)) | (yCol & (Up | Down));
	}

	bool Entity::IsColliding(Collision collisionSide) {
		return (collision & collisionSide) != 0;
	}

	double Entity::CalcStepSize(double vel) {
		if (abs(vel) < .5) {
			return 0.0;
		}
		return (vel > 0.0) ? min(vel, 0.5) : max(vel, -0.5);
	}

	int Entity::CheckCollision() {
		if(!_grid) {
			return None;
		}
		CollidingTiles.clear();
		int collision = None;
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
					if(abs(diffX) <= diff.X()){
						collision |= Left;
					}
					
					diffX = bottomRight.X() - tileCenter.X();
					if(abs(diffX) <= diff.X()){
						collision |= Right;
					}
					
				}
				if(abs(absoluteTilePositionTL.X() - topLeft.X()) < _size->X()){
					double diffY = topLeft.Y() - tileCenter.Y();
					if(abs(diffY) <= diff.Y()){
						collision |= Up;
					}
					diffY = bottomRight.Y() - tileCenter.Y();
					if(abs(diffY) <= diff.Y()){
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