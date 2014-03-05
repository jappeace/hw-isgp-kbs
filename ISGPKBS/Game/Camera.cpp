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

		double camFix2 = 200 * (_player->_xVel * 0.0015);

		_camFix = _camFix + (camFix2 - _camFix) * (3 * elapsed);

		_position.SetX(_position.GetX() + ((_player->_position.GetX() - _position.GetX()) + _camFix) * (4 * elapsed));
		_position.SetY(_position.GetY() + (_player->_position.GetY() - _position.GetY()) * (4 * elapsed));
	}

	// From static to dynamic
	Point Camera::ToFrom(Point p) {
		Point tmp = Point(0,0);
		
		tmp.SetX((p.GetX() - _position.GetX()) + 384);
		tmp.SetY((p.GetY() - _position.GetY()) + 384);

		return tmp;
	}

	// From static to dynamic
	Point Camera::FromTo(Point p) {
		return ToFrom(p);
	}
}