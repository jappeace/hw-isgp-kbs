#include "gravitybehaviour.h"
#include "Player.h"

namespace isgp{
	Player::Player(Point position) {
		_maxVel = 7;
		_accel = 40;
		_deAccel = 20;

		_position = position;
		_xVel = 0;
		_yVel = 0;
		_leftKey = false;
		_rightKey = false;
		_upKey = false;
		_spaceKey = false;
		_collision = false;
		_behaviours = new vector<BehaviourInterface*>();
		_behaviours->push_back(new GravityBehaviour(this));
	}


	Player::~Player(void) {
		// Delete references in vector
		for (BehaviourInterface* behaviour = _behaviours->front(); behaviour != _behaviours->back(); ++behaviour) {
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

		if (!_leftKey && !_rightKey && _collision && _xVel < 1 && _xVel > -1) {
			_xVel = 0;
		}

		_position.SetX(_position.GetX() + (_xVel));
		_position.SetY(_position.GetY() + (_yVel));

		for (unsigned int i = 0; i < _behaviours->size(); ++i) {
			_behaviours->at(i)->Update(milisec);
		}

		if (_position.GetY() > 220) { 
			_position.SetY(221);
			_collision = true;
		} else {
			_collision = false;
		}
		
		if (_upKey && _position.GetY() >= 221) {
			_yVel = -500 * elapsed;
		}
	}
	
	void Player::AddToVelocityY(double y) {
		_yVel += y;
	}

	void Player::Paint(Graphics* g) {
		_graphics = g;

		_graphics->DrawRect(_position, Point(_position.GetX() + 32, _position.GetY() + 32));
	}
}
