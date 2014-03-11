#pragma once

#include <vector>
#include <math.h>

#include "IBehaviour.h"
#include "IPaintable.h"
#include "Player.h"

namespace isgp {
	class Enemy : public IPaintable
	{
	public:
		Enemy(Point, Player*);
		~Enemy(void);
		virtual void Paint(Graphics* g);
		virtual void Update(double) = 0;
	protected:
		vector<IBehaviour*>* _behaviours;
		double _accel, _deAccel, _xVel, _yVel, _aVel, _radAngle;
		Point _position;
		Player* _player;
	private:
		Graphics* _graphics;
	};
}

