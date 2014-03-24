#include "Ghost.h"

namespace isgp {
	Ghost::Ghost(Vector2D point, Player* player) {
		_aVel = 0;
		_facingRight = true;
		_position = point;
		_player = player;
		
		_velocity = new Vector2D(0,0);
		_animation = new Animation("tiles/boo.bmp", Size(32, 32), 2, 250);
	}

	Ghost::~Ghost() {
		delete _velocity;
		delete _animation;
	}

	void Ghost::Update(double milisec) {
		double elapsed = milisec / 1000;
		double range = sqrt(pow(_position.X() - _player->GetPosition().X(), 2) + pow(_position.Y() - _player->GetPosition().Y(), 2));

		if (range < 26) {
			_player->Kill();
			_velocity->X(-_velocity->X());
			_velocity->Y(-_velocity->Y());
		}else if (range < 800) {
			if (_aVel < 300) {
				_aVel += (650 * elapsed);
			}
			
			_radAngle = atan2(_player->GetPosition().Y() - _position.Y(), _player->GetPosition().X() - _position.X());

			double targetXVel = _aVel * cos(_radAngle);
			double targetYVel = _aVel * sin(_radAngle);
			
			_velocity->X(_velocity->X() + (targetXVel - _velocity->X()) * elapsed);
			_velocity->Y(_velocity->Y() + (targetYVel - _velocity->Y()) * elapsed);
		}else{
			if (_aVel > 0) {
				_radAngle = atan2(_velocity->Y(), _velocity->X());
				_aVel = sqrt((_velocity->X() * _velocity->X()) + (_velocity->Y() * _velocity->Y()));

				_aVel -= (2000 * elapsed);
				if (_aVel < 0){ _aVel = 0; }

				_velocity->X(_aVel * cos(_radAngle));
				_velocity->Y(_aVel * sin(_radAngle));
			}
		}

		if (_velocity->X() > 0.0) {
			_facingRight = true;
		}else{
			_facingRight = false;
		}

		_position.X(_position.X() + (_velocity->X() * elapsed));
		_position.Y(_position.Y() + (_velocity->Y() * elapsed));
		_animation->OnUpdate(milisec);
	}

	void Ghost::AddToVelocityY(double) {}

	void Ghost::Paint(Graphics* g) {
		Vector2D offset(0, 0);
		if (!_facingRight) {
			offset.Y(32);
		}

		_animation->Render(g, _position, offset);
	}
}
