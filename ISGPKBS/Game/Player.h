#pragma once

#include <vector>

#include "IBehaviour.h"
#include "IPaintable.h"

namespace isgp {
	class Player : public IPaintable
	{
	public:
		Player(Vector2D position);
		~Player(void);
		void Paint(Graphics* g) override;
		void Update(const double);
		void AddToVelocityY(double y);
		Vector2D _position;
		bool _leftKey, _rightKey, _upKey, _spaceKey, _collision;
		double _xVel, _yVel, _maxVel;
	private:
		vector<IBehaviour*>* _behaviours;
		Graphics* _graphics;
		double _accel, _deAccel;
	};
}

