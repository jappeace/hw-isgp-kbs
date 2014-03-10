#include "Enemy.h"

namespace isgp {
	Enemy::Enemy(Point position, Player* player)
	{
		_position = position;
		_player = player;
		_aVel = 700;
		_xVel = 0;
		_yVel = 0;
	}

	Enemy::~Enemy(void)
	{
	}

	void Enemy::Update(double milisec) {
		
	}

	void Enemy::Paint(Graphics* g) {
		_graphics = g;

		_graphics->DrawRect(_position, Point(_position.GetX() + 32, _position.GetY() + 32));
	}
}
