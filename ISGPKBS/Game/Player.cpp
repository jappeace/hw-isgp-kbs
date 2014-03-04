#pragma once

#include "Player.h"
#include <vector>
#include "tile.h"
#include "Entity.h"
#include "GridGraphicTranslator.h"
namespace isgp{

	Player::Player(Point position) {
		_maxVel = 10;
		_accel = 1;
		_deAccel = 0.5;

		_position = position;
		_velocity = Vector2D(0, 0);
		_leftKey = false;
		_rightKey = false;
		_upKey = false;
		_spaceKey = false;
		_collision = false;
	}

	void Player::Update() {
		if (_leftKey && _velocity.x > -_maxVel) { 
			if (_collision) {
				_velocity.x -= _accel;
			} else { 
				_velocity.x -= _deAccel;
			}
		} else if (_velocity.x < 0 && _collision) {
			_velocity.x += _deAccel;
		}
		
		if (_rightKey && _velocity.x < _maxVel) { 
			if (_collision) {
				_velocity.x += _accel;
			} else { 
				_velocity.x += _deAccel;
			}
		} else if (_velocity.x > 0 && _collision) {
			_velocity.x -= _deAccel;
		}

		collision = CheckCollision(Point(_position.GetX() + _velocity.x, _position.GetY() + _velocity.y), 
										Point(_position.GetX() + _velocity.y + 16, _position.GetY() + _velocity.y + 32));
		
		if((_velocity.x < 0 && !(collision & Left)) || _velocity.x > 0 && !(collision & Right)) {
			_position.SetX(_position.GetX() + _velocity.x);
		}
		
		if(!(collision & Down)) {
			_velocity.y = 4;
			if(_velocity.y > 0) {
				_position.SetY(_position.GetY() + _velocity.y);
			}
			OutputDebugString("Nothing");
		} else {
			OutputDebugString("collide");
		}
		
		/*if(_velocity.y < 0 && !(collision & Up)) {
			_position.SetY(_position.GetY() + _velocity.y);
		}*/
		//if(_velocity.y > 0 && !(collision & Up) || _velocity.y < 0 && !(collision & Down)) {
			
		//}
		
		
		if (_upKey && _position.GetY() >= 520) { _velocity.y = -12; }
		if(_position.GetY() >= 520) {_position.SetY(0);}
	}

	void Player::Paint(Graphics* g) {
		_graphics = g;

		

		Point topLeft = this->_position;
		Point bottomRight = Point(this->_position.GetX() + 16, this->_position.GetY() + 32);
		GridGraphicTranslator translator = GridGraphicTranslator();
		vector<Tile*> includedTiles = _grid->GetTilesInRectangle(topLeft, bottomRight);
		
		g->SetColor(RGB(255, 0, 0));
		for(unsigned int i = 0; i < includedTiles.size(); i++) {
			Tile* t = includedTiles.at(i);
			Point* p = &translator.FromTo(*t->GetPosition());
			includedTiles.at(i)->Paint(g);
			g->DrawRect((int)p->GetX(), (int)p->GetY(), (int)p->GetX() + 16, (int)p->GetY() + 16);
		}

		g->SetColor(RGB(0, 255, 0));
		for(unsigned int i = 0; i < CollidingTiles.size(); i++) {
			Tile* t = CollidingTiles.at(i);
			Point* p = &translator.FromTo(*t->GetPosition());
			CollidingTiles.at(i)->Paint(g);
			g->DrawRect((int)p->GetX(), (int)p->GetY(), (int)p->GetX() + 16, (int)p->GetY() + 16);
		}

		g->SetColor(RGB(0, 0, 0));

		_graphics->DrawRect(_position, Point(_position.GetX() + 16, _position.GetY() + 32));
		
		g->DrawStr(Point(10, 40), collision & Up ? "Up: true" : "Up: false");
		g->DrawStr(Point(10, 55), collision & Down ? "Down: true" : "Down: false");
		g->DrawStr(Point(10, 70), collision & Left ? "Left: true" : "Left: false");
		g->DrawStr(Point(10, 85), collision & Right ? "Right: true" : "Right: false");

	}
}
