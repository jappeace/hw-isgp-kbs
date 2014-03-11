#include "Ghost.h"

namespace isgp {
	Ghost::Ghost(Vector2D point, Player* player) : Enemy(point, player) {
		_aVel = 0;
	}

	void Ghost::Update(double milisec) {
		double elapsed = milisec / 1000;
		double range = sqrt(pow(_position.X() - _player->_position.X(), 2) + pow(_position.Y() - _player->_position.Y(), 2));

		if (range < 26) {
			_xVel = -_xVel;
			_yVel = -_yVel;
		}else if (range < 600) {
			if (_aVel < 700) {
				_aVel += (2000 * elapsed);
			}
			
			_radAngle = atan2(_player->_position.Y() - _position.Y(), _player->_position.X() - _position.X());

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

		_position.X(_position.X() + (_xVel * elapsed));
		_position.Y(_position.Y() + (_yVel * elapsed));
	}
}
