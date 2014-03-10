#include "gravitybehaviour.h"
#include "Player.h"

namespace isgp{
	Player::Player(Vector2D position) {
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
		_behaviours = new vector<IBehaviour*>();
		_behaviours->push_back(new GravityBehaviour(this));
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
		if(_grid->CanDoMove(this->_position, Vector2D((_xVel * elapsed), 0.0))) {
			_position.X(_position.X() + (_xVel * elapsed));
		}
		if(_grid->CanDoMove(this->_position, Vector2D(0.0, (_yVel * elapsed)))) {
			_position.Y(_position.Y() + (_yVel * elapsed));
		}

		for (unsigned int i = 0; i < _behaviours->size(); ++i) {
			_behaviours->at(i)->Update(milisec);
		}

		if (_position.Y() > 220.0) { 
			_position.Y(221.0);
			_collision = true;
		} else {
			_collision = false;
		}
		
		if (_upKey && _position.Y() >= 221.0) {
			_yVel = -650;
		}
	}

	void Player::MoveTo(int x, int y) {
		if(_grid->CanDoMove(this->_position, Vector2D(x, 0))) {

		}
	}
	
	void Player::AddToVelocityY(double y) {
		if(_grid->CanDoMove(this->_position, Vector2D(0.0, y))) {
			_yVel += y;
		} else {
			int a = 2;
		}
	}

	void Player::Paint(Graphics* g) {
		_graphics = g;
		
		_graphics->DrawRect(_position, Vector2D(_position.X() + 16, _position.Y() + 32));
		
#ifdef _DEBUG
		_graphics->DrawStaticRect(Vector2D(395, 395), Vector2D(405, 405));
#endif
	}
}
