#pragma once

#include "IPaintable.h"

namespace isgp {
	class Player : public IPaintable
	{
	public:
		Player(Point position);
		~Player(void);
		void Paint(Graphics* g) override;
		void Update();
		Point position;
		bool _leftKey, _rightKey, _upKey, _collision;
	private:
		Graphics* _graphics;
		double _xVel, _yVel, _maxVel, _accel, _deAccel;
	};
}

