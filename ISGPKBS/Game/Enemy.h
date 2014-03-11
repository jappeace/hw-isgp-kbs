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
		Enemy(Vector2D position, Player*);
		~Enemy(void);
		void Paint(Graphics* g) override;
		virtual void Update(double) = 0;
	protected:
		vector<IBehaviour*>* _behaviours;
		double _accel, _deAccel, _xVel, _yVel, _aVel, _radAngle;
		Vector2D _position;
		Player* _player;
	private:
		Graphics* _graphics;
	};
}

