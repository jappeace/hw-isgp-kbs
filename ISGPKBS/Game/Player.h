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
		void AddBehaviour(IBehaviour*);
		void RemoveBehaviour(IBehaviour*);
		void Set_has_gravity_boots(bool hasBoots);
		bool Get_has_gravity_boots();
		static const Size InitSize;
	private:
		vector<IBehaviour*>* _behaviours;
		double _maxVel;
		double _accel, 
			_deAccel;
		Animation* _animation;
		bool _facingRight;
		// Tracks if the player has equiped the gravity boots
		bool _has_gravity_boots;
	};
}

