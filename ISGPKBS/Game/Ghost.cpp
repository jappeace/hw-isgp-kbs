#include "Ghost.h"

namespace isgp {
	Ghost::Ghost(Point point, Player* player) : Enemy(point, player) {
		_aVel = 0;
		_facingRight = true;
	}

	void Ghost::Update(double milisec) {
		double elapsed = milisec / 1000;
		double range = sqrt(pow(_position.GetX() - _player->_position.GetX(), 2) + pow(_position.GetY() - _player->_position.GetY(), 2));

		if (range < 26) {
			_xVel = -_xVel;
			_yVel = -_yVel;
		}else if (range < 700) {
			if (_aVel < 700) {
				_aVel += (2000 * elapsed);
			}
			
			_radAngle = atan2(_player->_position.GetY() - _position.GetY(), _player->_position.GetX() - _position.GetX());

			double targetXVel = _aVel * cos(_radAngle);
			double targetYVel = _aVel * sin(_radAngle);
			
			_xVel = _xVel + (targetXVel - _xVel) * elapsed;
			_yVel = _yVel + (targetYVel - _yVel) * elapsed;
		}else{
			if (_aVel > 0) {
				_radAngle = atan2(_yVel, _xVel);
				_aVel = sqrt((_xVel * _xVel) + (_yVel * _yVel));

				_aVel -= (2000 * elapsed);
				if (_aVel < 0){ _aVel = 0; }

				_xVel = _aVel * cos(_radAngle);
				_yVel = _aVel * sin(_radAngle);
			}
		}

		if (_xVel > 0.0) {
			_facingRight = true;
		}else{
			_facingRight = false;
		}

		_position.SetX(_position.GetX() + (_xVel * elapsed));
		_position.SetY(_position.GetY() + (_yVel * elapsed));
	}

	void Ghost::Paint(Graphics* g) {
		_graphics = g;

		if (_facingRight) {
			g->DrawBitmap(".\\tiles\\boo.bmp", this->_position, Size(32, 32));
		}else{
			g->DrawBitmap(".\\tiles\\boo.bmp", this->_position, Point(32, 0), Size(32, 32));
		}
	}
}
