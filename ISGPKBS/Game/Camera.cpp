#include "Camera.h"

namespace isgp{
	Camera::Camera(Player* player) {
		_player = player;
		_position = player->_position;
	}


	Camera::~Camera(void) {
	}

	void Camera::Update() {
		_position.SetX(_position.GetX() + (_player->_position.GetX() - _position.GetX()) * 0.1);
		_position.SetY(_position.GetY() + (_player->_position.GetY() - _position.GetY()) * 0.1);
	}

	Point Camera::ToFrom(Point p) {
		Point tmp = Point(0,0);
		
		tmp.SetX((_player->_position.GetX() - _position.GetX()) + 384);
		tmp.SetY((_player->_position.GetY() - _position.GetY()) + 384);

		return tmp;
	}

	Point Camera::FromTo(Point p) {
		Point tmp = Point(0,0);
		
		tmp.SetX((_player->_position.GetX() - _position.GetX()) + 384);
		tmp.SetY((_player->_position.GetY() - _position.GetY()) + 384);

		return tmp;
	}
}