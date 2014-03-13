#pragma once

#include <vector>

#include "Animation.h"
#include "IBehaviour.h"
#include "IPaintable.h"
#include "Grid.h"
#include "Entity.h"
namespace isgp {
	class Player : public Entity
	{
	public:
		Player(Vector2D position);
		~Player(void);
		void Paint(Graphics* g) override;
		void Update(const double);
		void AddToVelocityY(double y);
		bool _leftKey, _rightKey, _upKey, _spaceKey;
		

		static const Size InitSize;
		
	private:
		vector<IBehaviour*>* _behaviours;
		double _maxVel;
		double _accel, 
			_deAccel;
		Animation* _animation;
		bool _facingRight;
	};
}

