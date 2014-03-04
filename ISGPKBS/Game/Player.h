#pragma once

#include <vector>

#include "behaviourinterface.h"
#include "IPaintable.h"
#include "Entity.h"
namespace isgp {
	class Player : public Entity
	{
	public:
		Player(Point);
		~Player();
		void Paint(Graphics* g) override;
		void Update(const double);
		void AddToVelocityY(double y);
		Point _position;
		bool _leftKey, _rightKey, _upKey, _spaceKey, _collision;
		double _xVel, _yVel, _maxVel;
		int collision;
	private:
		vector<BehaviourInterface*>* _behaviours;
		Graphics* _graphics;
		double _accel, _deAccel;
	};
}

