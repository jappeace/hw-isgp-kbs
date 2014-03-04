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
