#include "gravitybehaviour.h"
#include "Player.h"

namespace isgp{
	Player::Player(Point position) {
		_maxVel = 500;
		_accel = 2200;
		_deAccel = 1100;

		_position = position;
		_xVel = 0;
		_yVel = 0;
		_leftKey = false;
		_rightKey = false;
		_upKey = false;
		_spaceKey = false;
		_collision = false;
		_facingRight = true;
		_behaviours = new vector<IBehaviour*>();
		_behaviours->push_back(new GravityBehaviour(this));
		
		_animation = Animation(".\\tiles\\megaman.bmp", Size(32, 32), 4, 200);
	}

	Player::~Player(void) {
		// Delete references in vector
		for (IBehaviour* behaviour = _behaviours->front(); behaviour != _behaviours->back(); ++behaviour) {
			delete behaviour;
		}
		// Delete vector
		delete _behaviours;
	}

	void Player::Update(const double milisec) {
		double elapsed = milisec / 1000;

		if (_leftKey && _xVel > -_maxVel) { 
			if (_collision) {
				_xVel -= _accel * elapsed;
			} else { 
				_xVel -= _deAccel * elapsed;
			}
		} else if (_xVel < 0 && _collision) {
			_xVel += _deAccel * elapsed;
		}
		
		if (_rightKey && _xVel < _maxVel) { 
			if (_collision) {
				_xVel += _accel * elapsed;
			} else { 
				_xVel += _deAccel * elapsed;
			}
		} else if (_xVel > 0 && _collision) {
			_xVel -= _deAccel * elapsed;
		}

		if (!_leftKey && !_rightKey && _collision && _xVel < 20 && _xVel > -20) {
			_xVel = 0;
		}

		_position.SetX(_position.GetX() + (_xVel * elapsed));
		_position.SetY(_position.GetY() + (_yVel * elapsed));

		for (unsigned int i = 0; i < _behaviours->size(); ++i) {
			_behaviours->at(i)->Update(milisec);
		}

		if (_position.GetY() > 220.0) { 
			_position.SetY(221.0);
			_collision = true;
		} else {
			_collision = false;
		}
		
		if (_upKey && _position.GetY() >= 221.0) {
			_yVel = -650;
		}

		// Update Facing
		if (_xVel != 0) {
			_facingRight = _xVel > 0.0;
		}

		// Update animation
		_animation.OnUpdate(milisec);

		if (_xVel == 0) {
			_animation.Reset();
		}
	}
	
	void Player::AddToVelocityY(double y) {
		_yVel += y;
	}

	void Player::Paint(Graphics* g) {
		static int const kSpriteSize = 32;

		int facingOffset = 0;
		if (!_facingRight) {
			facingOffset = kSpriteSize;
		}

		if (!_collision) {
			// In the air
			Point offset((2 * kSpriteSize) + facingOffset, 2 * kSpriteSize);
			g->DrawBitmap(".\\tiles\\megaman.bmp", this->_position, offset, Size(kSpriteSize, kSpriteSize));
		} else if (!_leftKey && !_rightKey) {
			// Standing still on the ground
			Point offset(facingOffset, 2 * kSpriteSize);
			g->DrawBitmap(".\\tiles\\megaman.bmp", this->_position, offset, Size(kSpriteSize, kSpriteSize));
		} else {
			// Moving
			Point offset(0, facingOffset);
			_animation.Render(g, this->_position, offset);
		}

#ifdef _DEBUG
		// Facing info
		if (_facingRight) {
			g->DrawRect(Point(_position.GetX() + 32, _position.GetY() + 8), Point(_position.GetX() + 40, _position.GetY() + 16));
		} else {
			g->DrawRect(Point(_position.GetX(), _position.GetY() + 8), Point(_position.GetX() - 8, _position.GetY() + 16));
		}

		g->DrawStaticRect(Point(395, 395), Point(405, 405));
#endif
	}
}
