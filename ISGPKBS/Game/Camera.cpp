#include "Camera.h"

namespace isgp{
	Camera::Camera(Player* player, Grid* grid) {
		_player = player;
		_position = player->_position;
		_camFix = 0;
		_grid = grid;
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

		Vector2D fix = ((AbstractWindow::WindowSize - Player::InitSize) * Vector2D(1.0,1.35)) / Vector2D(2);
		Vector2D fix2 = GridGraphicTranslator().FromTo(*_grid->GetSize()) - AbstractWindow::WindowSize;
		fix2 += fix;
		
		if (_position.Y() > fix2.Y()) { _position.Y(fix2.Y()); }
		if (_position.X() > fix2.X()) { _position.X(fix2.X()); }
		
		if (_position.Y() < fix.Y()) { _position.Y(fix.Y()); }
		if (_position.X() < fix.X()) { _position.X(fix.X()); }
	}

	// From static to dynamic
	Vector2D Camera::ToFrom(Vector2D p) {
		p -= _position;
		p += ((AbstractWindow::WindowSize - Player::InitSize) * Vector2D(1.0,1.35)) / Vector2D(2);

		return p;
	}

	// From static to dynamic
	Vector2D Camera::FromTo(Vector2D p) {
		return ToFrom(p);
	}
	Vector2D Camera::GetPosition(){
		return _position;
	}
}