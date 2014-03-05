#pragma once
#include "gravitybehaviour.h"
#include "Player.h"

#include "Player.h"
#include <vector>
#include "tile.h"
#include "Entity.h"
#include "GridGraphicTranslator.h"
namespace isgp{

	Player::Player(Point position) {
		_maxVel = 500;
		_accel = 2200;
		_deAccel = 1100;

		_position = position;
		_velocity = Vector2D(0, 0);
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
		collision = CheckCollision(this->_position, Point(this->_position.GetX() + 16, this->_position.GetY() + 32));
		if (_leftKey && _xVel > -_maxVel) { 
			if (_collision) {
				_xVel -= _accel * elapsed;
			} else { 
				_xVel -= _deAccel * elapsed;
			}
		} else if (_velocity.x < 0 && _collision) {
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
		if(collision & Down && _yVel < 0) {
			//_position.SetY(_position.GetY() + (_yVel * elapsed));
		} else {
			_position.SetY(_position.GetY() + (_yVel * elapsed));
		}
		_position.SetX(_position.GetX() + (_xVel * elapsed));
		

		for (unsigned int i = 0; i < _behaviours->size(); ++i) {
			_behaviours->at(i)->Update(milisec);
		}

		if (_position.GetY() > 220.0) { 
			_position.SetY(221.0);
			_collision = true;
		} else {
			_collision = false;
		}
		
		if (_upKey && _position.GetY() >= 221.0) {
			_yVel = -650;
		}
	}
	
	void Player::AddToVelocityY(double y) {
		_yVel += y;
	}

	void Player::Paint(Graphics* g) {
		_graphics = g;
		

		Point topLeft = this->_position;
		Point bottomRight = Point(this->_position.GetX() + 16, this->_position.GetY() + 32);
		GridGraphicTranslator translator = GridGraphicTranslator();
		
#ifdef _DEBUG
		_graphics->DrawStaticRect(Point(395, 395), Point(405, 405));
#endif
		vector<Tile*> includedTiles = _grid->GetTilesInRectangle(topLeft, bottomRight);
		
		g->SetColor(RGB(255, 0, 0));
		for(unsigned int i = 0; i < includedTiles.size(); i++) {
			Tile* t = includedTiles.at(i);
			Point* p = &translator.FromTo(*t->GetPosition());
			includedTiles.at(i)->Paint(g);

			g->DrawRect(Point((int)p->GetX(), (int)p->GetY()), Point((int)p->GetX() + 16, (int)p->GetY() + 16));
		}

		g->SetColor(RGB(0, 255, 0));
		for(unsigned int i = 0; i < CollidingTiles.size(); i++) {
			Tile* t = CollidingTiles.at(i);
			Point* p = &translator.FromTo(*t->GetPosition());
			CollidingTiles.at(i)->Paint(g);
			g->DrawRect(Point((int)p->GetX(), (int)p->GetY()), Point((int)p->GetX() + 16, (int)p->GetY() + 16));
		}

		g->SetColor(RGB(0, 0, 0));

		_graphics->DrawRect(_position, Point(_position.GetX() + 16, _position.GetY() + 32));
		
		g->DrawStr(Point(10, 40), collision & Up ? "Up: true" : "Up: false");
		g->DrawStr(Point(10, 55), collision & Down ? "Down: true" : "Down: false");
		g->DrawStr(Point(10, 70), collision & Left ? "Left: true" : "Left: false");
		g->DrawStr(Point(10, 85), collision & Right ? "Right: true" : "Right: false");

	}
}
