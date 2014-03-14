#include "gravitybehaviour.h"
#include "Player.h"
#include "CollisionDetection.h"
namespace isgp{
const Size Player::InitSize(32, 32);
	Player::Player(Vector2D position) {
		_maxVel = 350;
		_accel = 2200;
		_deAccel = 1100;

		_position = position;
		_velocity = new Vector2D();
		_leftKey = false;
		_rightKey = false;
		_upKey = false;
		_spaceKey = false;
		_size = new Size(Player::InitSize);
		_behaviours = new vector<IBehaviour*>();
		_behaviours->push_back(new GravityBehaviour(this));
		
		_facingRight = true;
		_animation = new Animation(".\\tiles\\megaman.bmp", (Size) *_size, 4, 200);
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
		if (!_leftKey && !_rightKey && (collision & Down) && _velocity->X() < 100 && _velocity->X() > -100) {
			_velocity->X(0);
		}

		//behaviors
		for (unsigned int i = 0; i < _behaviours->size(); ++i) {
			_behaviours->at(i)->Update(milisec);
		}
		Move((*_velocity) * Vector2D(elapsed));
		if((collision & Down && _velocity->Y() > 0) || (collision & Up && _velocity->Y() < 0)) { 
			_velocity->Y(0);
		}
		if((collision & Right && _velocity->X() > 0) || (collision & Left && _velocity->X() < 0)) { 
			_velocity->X(0);
		}

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
	
	void Player::AddToVelocityY(double y) {
		_velocity->Y(_velocity->Y() + y);
	}

	void Player::Paint(Graphics* g) {
#ifdef _DEBUG
		GridGraphicTranslator translator = GridGraphicTranslator();
		vector<Tile*> includedTiles = _grid->GetTilesInRectangle(_position, _position + *_size + Vector2D(2));
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

		if (!_facingRight) {
			facingOffset = kSpriteSize;
		}

		if (_velocity->Y() != 0.0) {
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
#ifdef _DEBUG
		g->DrawStaticRect(Vector2D(395, 395), Vector2D(405, 405));
#endif
	}
}
