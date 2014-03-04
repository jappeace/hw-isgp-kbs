#pragma once

#include <vector>

#include "behaviourinterface.h"
#include "IPaintable.h"

namespace isgp {
	class Player : public IPaintable
	{
	public:
		Player(Point position);
		~Player(void);
		void Paint(Graphics* g) override;
		void Update(const double);
		void AddToVelocityY(double y);
		Point _position;
		bool _leftKey, _rightKey, _upKey, _spaceKey, _collision;
	private:
		vector<BehaviourInterface*>* _behaviours;
		Graphics* _graphics;
		double _xVel, _yVel, _maxVel, _accel, _deAccel;
	};
}

