#include "gravitybehaviour.h"
#include "Player.h"
#include "CollisionDetection.h"
namespace isgp{
	Player::Player(Vector2D position) {
		_maxVel = 500;
		_accel = 2200;
		_deAccel = 1100;

		_position = position;
		_velocity = new Vector2D();
		_leftKey = false;
		_rightKey = false;
		_upKey = false;
		_spaceKey = false;
		_size = new Size(32, 32);
		_behaviours = new vector<IBehaviour*>();
		_behaviours->push_back(new GravityBehaviour(this));
		
		_facingRight = true;
		_animation = new Animation(".\\tiles\\megaman.bmp", Size(32, 32), 4, 200);
	}

	Player::~Player(void) {
		// Delete references in vector
		for (IBehaviour* behaviour = _behaviours->front(); behaviour != _behaviours->back(); ++behaviour) {
			delete behaviour;
		}
		// Delete vector
		delete _behaviours;
		delete _size;
		delete _velocity;
		delete _animation;
	}

	void Player::Update(const double milisec) {
		double elapsed = milisec / 1000;

		collision = CheckCollision();

		if(_leftKey && _velocity->X() > -_maxVel) {
			if(collision & Down){
				_velocity->X(_velocity->X() - (_accel * elapsed));
			} else {
				_velocity->X(_velocity->X() - (_deAccel * elapsed));
			}
		} else if(_velocity->X() < 0 && (collision & Down)) {
			_velocity->X(_velocity->X() + _deAccel * elapsed);
		}

		if(_rightKey && _velocity->X() < _maxVel) {
			if(collision & Down) {
				_velocity->X(_velocity->X() + _accel * elapsed);
			} else {
				_velocity->X(_velocity->X() + _deAccel * elapsed);
			}
		} else if(_velocity->X() > 0 && (collision & Down)) {
			_velocity->X(_velocity->X() - _deAccel * elapsed);
		}
		
		// no wandering
		if (!_leftKey && !_rightKey && (collision & Down) && _velocity->X() < 20 && _velocity->X() > -20) {
			_velocity->X(0);
		}

		for (unsigned int i = 0; i < _behaviours->size(); ++i) {
			_behaviours->at(i)->Update(milisec);
		}
		if((collision & Down && _velocity->Y() > 0) || (collision & Up && _velocity->Y() < 0)) { 
			_velocity->Y(0);
		}
		if((collision & Right && _velocity->X() > 0) || (collision & Left && _velocity->X() < 0)) { 
			_velocity->X(0);
		}
		Move((*_velocity) * Vector2D(elapsed));

		if(_upKey && (collision & Down)) {
			_velocity->Y(-650);
		}

		// Update Facing
		if (_velocity->X() != 0) {
			_facingRight = _velocity->X() > 0.0;
		}

		// Update animation
		_animation->OnUpdate(milisec);

		if (_velocity->X() == 0) {
			_animation->Reset();
		}
	}

	bool Player::Collides(int x, int y) {
		_position += Vector2D(x, y);
		int doesCollide = CheckCollision();
		_position -= Vector2D(x, y);
		return doesCollide == None;
	}

	void Player::Move(Vector2D velocity) {
		if(velocity.X() != 0 || velocity.Y() != 0) {
			double allowedX = 0;
			double allowedY = 0;
			bool hasCollided = false;

			while(true) {
				double stepSizeX = CalcStepSize(velocity.X() - allowedX);
				double stepSizeY = CalcStepSize(velocity.Y() - allowedY);

				bool canMoveX = stepSizeX != 0 && Collides((int)(allowedX + stepSizeX), 0);
				bool canMoveY = stepSizeY != 0 && Collides(0, 1 + (int)(allowedY + stepSizeY));
				if(canMoveX) {
					allowedX += stepSizeX;
				} else if(stepSizeX != 0  && !hasCollided) {
					hasCollided = true;
				}

				if(canMoveY) {
					allowedY += stepSizeY;
				} else if(stepSizeY != 0 && !hasCollided) {
					hasCollided = true;
				}

				if(!canMoveX && !canMoveY) {
					break;
				}
			}

			if(allowedX != 0 || allowedY != 0) {
				_position += Vector2D(allowedX, allowedY);
			}
			
		}
		
	}

	double Player::CalcStepSize(double vel) {
		if(abs(vel) < 0.01) {
			return 0.0;
		} else {
			return (vel > 0) ? min(vel, 1) : max(vel, -1);
		}
	}
	
	void Player::AddToVelocityY(double y) {
		_velocity->Y(_velocity->Y() + y);
	}

	void Player::Paint(Graphics* g) {
#ifdef _DEBUG
		g->DrawStaticRect(Vector2D(395, 395), Vector2D(405, 405));
		GridGraphicTranslator translator = GridGraphicTranslator();
		vector<Tile*> includedTiles = _grid->GetTilesInRectangle(_position, _position + *_size);

		g->SetColor(RGB(255, 0, 0));
		for(unsigned int i = 0; i < includedTiles.size(); i++) {
			Tile* t = includedTiles.at(i);
			Vector2D* p = &translator.FromTo(*t->GetPosition());
			includedTiles.at(i)->Paint(g);

			g->DrawRect(Vector2D((int)p->X(), (int)p->Y()), Vector2D((int)p->X() + 16, (int)p->Y() + 16));
		}

		g->SetColor(RGB(0, 255, 0));
		for(unsigned int i = 0; i < CollidingTiles.size(); i++) {
			Tile* t = CollidingTiles.at(i);
			Vector2D* p = &translator.FromTo(*t->GetPosition());
			CollidingTiles.at(i)->Paint(g);
			g->DrawRect(Vector2D((int)p->X(), (int)p->Y()), Vector2D((int)p->X() + 16, (int)p->Y() + 16));
		}
		g->SetColor(RGB(0, 0, 0));

		g->DrawStr(Vector2D(10, 40), collision & Up ? "Up: true" : "Up: false");
		g->DrawStr(Vector2D(10, 55), collision & Down ? "Down: true" : "Down: false");
		g->DrawStr(Vector2D(10, 70), collision & Left ? "Left: true" : "Left: false");
		g->DrawStr(Vector2D(10, 85), collision & Right ? "Right: true" : "Right: false");

		// Facing info
		if (_facingRight) {
			g->DrawRect(Vector2D(_position.X() + 32, _position.Y() + 8), Vector2D(_position.X() + 40, _position.Y() + 16));
		} else {
			g->DrawRect(Vector2D(_position.X(), _position.Y() + 8), Vector2D(_position.X() - 8, _position.Y() + 16));
		}
#endif
		static int const kSpriteSize = 32;

		int facingOffset = 0;
		//int collision = CheckCollision();

		if (!_facingRight) {
			facingOffset = kSpriteSize;
		}

		if ((collision & Down) == 0) {
			// In the air
			Vector2D offset((2 * kSpriteSize) + facingOffset, 2 * kSpriteSize);
			g->DrawBitmap(".\\tiles\\megaman.bmp", this->_position, offset, Size(kSpriteSize, kSpriteSize));
		} else if (!_leftKey && !_rightKey) {
			// Standing still on the ground
			Vector2D offset(facingOffset, 2 * kSpriteSize);
			g->DrawBitmap(".\\tiles\\megaman.bmp", this->_position, offset, Size(kSpriteSize, kSpriteSize));
		} else {
			// Moving
			Vector2D offset(0, facingOffset);
			_animation->Render(g, this->_position, offset);
		}
	}
}
