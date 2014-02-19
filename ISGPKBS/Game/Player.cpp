#include "Player.h"

namespace isgp{
	Player::Player(Point position) {
		_maxVel = 10;
		_accel = 1;
		_deAccel = 0.5;

		this->position = position;
		_xVel = 0;
		_yVel = 0;
		_leftKey = false;
		_rightKey = false;
		_upKey = false;
		_collision = false;
	}


	Player::~Player(void) {

	}

	void Player::Update() {
		if (_leftKey && _xVel > -_maxVel) { 
			if (_collision) {
				_xVel -= _accel;
			} else { 
				_xVel -= _deAccel;
			}
		} else if (_xVel < 0 && _collision) {
			_xVel += _deAccel;
		}
		
		if (_rightKey && _xVel < _maxVel) { 
			if (_collision) {
				_xVel += _accel;
			} else { 
				_xVel += _deAccel;
			}
		} else if (_xVel > 0 && _collision) {
			_xVel -= _deAccel;
		}

		position.SetX(position.GetX() - _xVel);
		position.SetY(position.GetY() - _yVel);

		if (position.GetY() > 520) { position.SetY(521); _collision = true; } else { _collision = false; }
		
		if (position.GetY() < 521) { _yVel += 1; }
		else { _yVel = 0; }
		if (_upKey && position.GetY() >= 520) { _yVel = -12; }
	}

	void Player::Paint(Graphics* g) {
		_graphics = g;

		_graphics->drawRect(Point(100, 100), Point(200, 200));
	}
}
