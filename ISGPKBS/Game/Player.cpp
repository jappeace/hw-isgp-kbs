#include "Player.h"

namespace isgp{
	Player::Player(Point position) {
		_maxVel = 10;
		_accel = 60;
		_deAccel = 30;

		_position = position;
		_xVel = 0;
		_yVel = 0;
		_leftKey = false;
		_rightKey = false;
		_upKey = false;
		_spaceKey = false;
		_collision = false;
	}


	Player::~Player(void) {

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

		if (!_leftKey && !_rightKey && _collision && _xVel < 1 && _xVel > -1) {
			_xVel = 0;
		}

		_position.SetX(_position.GetX() + (_xVel));
		_position.SetY(_position.GetY() + (_yVel));

		if (_position.GetY() > 512) { _position.SetY(512); _collision = true; } else { _collision = false; }
		
		if (_position.GetY() < 513) { _yVel += 60 * elapsed; }
		else { _yVel = 0; }
		if (_upKey && _position.GetY() >= 512) { _yVel = -600 * elapsed; }
	}

	void Player::Paint(Graphics* g) {
		_graphics = g;

		_graphics->DrawRect(_position, Point(_position.GetX() + 32, _position.GetY() + 32));
	}
}
