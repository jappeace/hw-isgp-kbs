#include "Player.h"
#include <vector>
#include "tile.h"

namespace isgp{

	Player::Player(Point position) {
		_maxVel = 10;
		_accel = 1;
		_deAccel = 0.5;

		_position = position;
		_velocity = Vector2D(0, 0);
		_leftKey = false;
		_rightKey = false;
		_upKey = false;
		_spaceKey = false;
		_collision = false;
	}



	enum Collision {
		None = 0x01,
		Left = 0x02,
		Up = 0x04,
		Right = 0x08,
		Down = 0x10
	};

	int CheckCollision(Point topLeft, Point bottomRight) {
		int returnVal = 0;
		//returnVal |= Left;
		//returnVal |= Down;
		return returnVal;
	}

	void Player::Update() {
		if (_leftKey && _velocity.x > -_maxVel) { 
			if (_collision) {
				_velocity.x -= _accel;
			} else { 
				_velocity.x -= _deAccel;
			}
		} else if (_velocity.x < 0 && _collision) {
			_velocity.x += _deAccel;
		}
		
		if (_rightKey && _velocity.x < _maxVel) { 
			if (_collision) {
				_velocity.x += _accel;
			} else { 
				_velocity.x += _deAccel;
			}
		} else if (_velocity.x > 0 && _collision) {
			_velocity.x -= _deAccel;
		}

		int collision = CheckCollision(Point(_position.GetX() + _velocity.x, _position.GetY() + _velocity.y), 
										Point(_position.GetX() + _velocity.y + 16, _position.GetY() + _velocity.y + 32));
		
		if((_velocity.x < 0 && !(collision & Left)) || _velocity.x > 0 && !(collision & Right)) {
			_position.SetX(_position.GetX() + _velocity.x);
		}


		if(_velocity.y < 0 && !(collision & Up) || _velocity.y > 0 && !(collision & Down)) {
			_position.SetY(_position.GetY() + _velocity.y);
		}
		
		

		if (_position.GetY() > 520) { _position.SetY(521); _collision = true; } else { _collision = false; }
		
		if (_position.GetY() < 521) { _velocity.y += 1; }
		else { _velocity.y = 0; }
		if (_upKey && _position.GetY() >= 520) { _velocity.y = -12; }
	}

	void Player::Paint(Graphics* g) {
		_graphics = g;

		_graphics->DrawRect(_position, Point(_position.GetX() + 16, _position.GetY() + 32));
	}
}
