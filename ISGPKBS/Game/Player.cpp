#include "gravitybehaviour.h"
#include "Player.h"
#include "CollisionDetection.h"
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
		_size = new Size(32, 32);
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
		delete _size;
	}

	void Player::Update(const double milisec) {
		double elapsed = milisec / 1000;

		if (_leftKey && _xVel > -_maxVel) { 
			if (collision & Down) {
				_xVel -= _accel * elapsed;
			} else { 
				_xVel -= _deAccel * elapsed;
			}
		} else if (_xVel < 0 && (collision & Down)) {
			_xVel += _deAccel * elapsed;
		}
		
		if (_rightKey && _xVel < _maxVel) { 
			if (collision & Down) {
				_xVel += _accel * elapsed;
			} else { 
				_xVel += _deAccel * elapsed;
			}
		} else if (_xVel > 0 && (collision & Down)) {
			_xVel -= _deAccel * elapsed;
		}

		if (!_leftKey && !_rightKey && (collision & Down) && _xVel < 20 && _xVel > -20) {
			_xVel = 0;
		}
		_position.X(_position.X() + (_xVel * elapsed));
		_position.Y(_position.Y() + (_yVel * elapsed));

		for (unsigned int i = 0; i < _behaviours->size(); ++i) {
			_behaviours->at(i)->Update(milisec);
		}

	}

	void Player::MoveTo(int x, int y) {
	}
	
	void Player::AddToVelocityY(double y) {
		_yVel += y;
	}

	void Player::Paint(Graphics* g) {
		_graphics = g;
		
		_graphics->DrawRect(_position, Vector2D(_position.X() + 16, _position.Y() + 32));
		
#ifdef _DEBUG
		_graphics->DrawStaticRect(Vector2D(395, 395), Vector2D(405, 405));
#endif
	}
}
