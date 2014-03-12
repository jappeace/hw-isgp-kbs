#include "Patrol.h"
#include "gravitybehaviour.h"
#include "CollisionDetection.h"

namespace isgp {
	Patrol::Patrol(Vector2D point, int range, Player* player) {
		_position = point;
		_player = player;
		
		_velocity = new Vector2D(0,0);
		_velocity->X(200);
		_startingPoint = point;
		_range = range;
		
		_behaviours = new vector<IBehaviour*>();
		_behaviours->push_back(new GravityBehaviour(this));

		_facingRight = true;
		_animation = new Animation(".\\tiles\\link.bmp", Size(32, 32), 2, 200);

		_size = new Vector2D(32, 32);
	}

	void Patrol::Update(double milisec) {
		double elapsed = milisec / 1000;
		double range = sqrt(pow(_position.X() - _startingPoint.X(), 2) + pow(_position.Y() - _startingPoint.Y(), 2));
		double collisionRange = sqrt(pow(_position.X() - _player->_position.X(), 2) + pow(_position.Y() - _player->_position.Y(), 2));

		collision = CheckCollision();

		if (collisionRange < 26) {
			//collision!
		}

		if (range > _range) {
			_velocity->X(-_velocity->X());
		}

		_position.X(_position.X() + (_velocity->X() * elapsed));
		_position.Y(_position.Y() + (_velocity->Y() * elapsed));

		// Update Facing
		if (_velocity->X() != 0) {
			_facingRight = _velocity->X() > 0.0;
		}

		// Update animation
		_animation->OnUpdate(milisec);

		if (_velocity->X() == 0) {
			_animation->Reset();
		}

		//Behaviors
		for (unsigned int i = 0; i < _behaviours->size(); ++i) {
			_behaviours->at(i)->Update(milisec);
		}

		//Collision
		if((collision & Down && _velocity->Y() > 0) || (collision & Up && _velocity->Y() < 0)) { 
			_velocity->Y(0);
		}
		if((collision & Right && _velocity->X() > 0) || (collision & Left && _velocity->X() < 0)) { 
			_velocity->X(-_velocity->X());
		}
	}

	void Patrol::AddToVelocityY(double y) {
		_velocity->Y(_velocity->Y() + y);
	}

	void Patrol::Paint(Graphics* g) {
		static int const kSpriteSize = 32;
		
		int facingOffset = 0;

		if (!_facingRight) {
			facingOffset = kSpriteSize;
		}

		Vector2D offset(0, facingOffset);
		_animation->Render(g, this->_position, offset);
	}
}
