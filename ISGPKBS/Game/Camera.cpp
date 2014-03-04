#include "Camera.h"

namespace isgp{
	Camera::Camera(Player* player) {
		_player = player;
		_position = player->_position;
		_camFix = 0;
	}


	Camera::~Camera(void) {
	}

	void Camera::Update() {
		double camFix2 = 200 * (_player->_xVel * 0.1);

		_camFix = _camFix + (camFix2 - _camFix) * 0.025;
		
		_position.SetX(_position.GetX() + ((_player->_position.GetX() - _position.GetX()) + _camFix) * 0.1);
		_position.SetY(_position.GetY() + (_player->_position.GetY() - _position.GetY()) * 0.1);
	}

	Point Camera::ToFrom(Point p) {
		Point tmp = Point(0,0);
		
		tmp.SetX((p.GetX() - _position.GetX()) + 384);
		tmp.SetY((p.GetY() - _position.GetY()) + 384);

		return tmp;
	}

	Point Camera::FromTo(Point p) {
		Point tmp = Point(0,0);
		
		tmp.SetX((p.GetX() - _position.GetX()) + 384);
		tmp.SetY((p.GetY() - _position.GetY()) + 384);

		return tmp;
	}
}