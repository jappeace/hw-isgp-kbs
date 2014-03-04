#pragma once

#include "IPaintable.h"
#include "Entity.h"
namespace isgp {
	class Player : public Entity
	{
	public:
		Player(Point);
		void Paint(Graphics* g) override;
		void Update() override;
		int collision;
		bool _leftKey, _rightKey, _upKey, _spaceKey, _collision;
	private:
		Graphics* _graphics;
		double _maxVel, _accel, _deAccel;
	};
}

