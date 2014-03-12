#include "Camera.h"

namespace isgp{
	Camera::Camera(Player* player) {
		_player = player;
		_position = player->_position;
		_camFix = 0;
	}


	Camera::~Camera(void) {
	}

	void Camera::Update(double milisec) {
		double elapsed = milisec / 1000;

		double camFix2 = 200 * (_player->GetVelocity()->X() * 0.0015);

		_camFix = _camFix + (camFix2 - _camFix) * (3 * elapsed);

		_position.X(
			_position.X() + 
			(
				(_player->_position.X() - _position.X()
			) + _camFix) * (4 * elapsed)
		);
		_position.Y(
			_position.Y() + (
				_player->_position.Y() - _position.Y()
			) * (4 * elapsed)
		);
	}

	// From static to dynamic
	Vector2D Camera::ToFrom(Vector2D p) {
		p -= _position;
		p += Vector2D(384,384);

		return p;
	}

	// From static to dynamic
	Vector2D Camera::FromTo(Vector2D p) {
		return ToFrom(p);
	}
}