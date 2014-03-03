#include "Player.h"
#include <vector>
#include "tile.h"
namespace isgp{
	Player::Player(Point position) {
		_maxVel = 10;
		_accel = 1;
		_deAccel = 0.5;

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

		_position.SetX(_position.GetX() + _xVel);
		_position.SetY(_position.GetY() + _yVel);

		if (_position.GetY() > 520) { _position.SetY(521); _collision = true; } else { _collision = false; }
		
		if (_position.GetY() < 521) { _yVel += 1; }
		else { _yVel = 0; }
		if (_upKey && _position.GetY() >= 520) { _yVel = -12; }
	}

	void Player::Paint(Graphics* g) {
		_graphics = g;

		_graphics->DrawRect(_position, Point(_position.GetX() + 32, _position.GetY() + 32));
	}
}
