#include "Patrol.h"

namespace isgp {
	Patrol::Patrol(Vector2D point, int range, Player* player) : Enemy(point, player) {
		_xVel = 200;
		_startingPoint = point;
		_range = range;
	}

	void Patrol::Update(double milisec) {
		double elapsed = milisec / 1000;
		double range = sqrt(pow(_position.X() - _startingPoint.X(), 2) + pow(_position.Y() - _startingPoint.Y(), 2));
		double collisionRange = sqrt(pow(_position.X() - _player->_position.X(), 2) + pow(_position.Y() - _player->_position.Y(), 2));

		if (collisionRange < 26) {
			//collision!
		}

		if (range > _range) {
			_xVel = -_xVel;
		}

		_position.X(_position.X() + (_xVel * elapsed));
		_position.Y(_position.Y() + (_yVel * elapsed));
	}
}
