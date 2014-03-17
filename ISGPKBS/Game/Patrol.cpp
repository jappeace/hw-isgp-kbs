#include "Patrol.h"
#include "gravitybehaviour.h"
#include "CollisionDetection.h"

namespace isgp {
	Patrol::Patrol(Vector2D point, int range, Player* player) : _movement_speed(200) {
		_position = point;
		_oldPosition = Vector2D(1337, 1337);
		_player = player;
		
		_velocity = new Vector2D(0,0);
		_velocity->X(_movement_speed);
		_startingPoint = point;
		_range = range;
		
		_behaviours = new vector<IBehaviour*>();
		_behaviours->push_back(new GravityBehaviour(this));

		_facingRight = true;
		_animation = new Animation("../tiles/link.bmp", Size(32, 32), 2, 200);

		_size = new Vector2D(32, 32);
	}

	void Patrol::Update(double milisec) {
		double elapsed = milisec / 1000;
		double range = _position.X() - _startingPoint.X();
		double collisionRange = sqrt(pow(_position.X() - _player->GetPosition().X(), 2) + pow(_position.Y() - _player->GetPosition().Y(), 2));

		if (collisionRange < 26) {
			// Collision with player, kill it!
			_player->Kill();
		}

		if (range > _range) {
			_velocity->X(-this->_movement_speed);
		} else if (range < -_range) {
			_velocity->X(this->_movement_speed);
		}

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

		Move(Vector2D((_velocity->X() * elapsed), (_velocity->Y() * elapsed)));

		//Collision
		if((collision & Down && _velocity->Y() > 0) || (collision & Up && _velocity->Y() < 0)) { 
			_velocity->Y(0);
		}
		if((collision & Right && _velocity->X() > 0) || (collision & Left && _velocity->X() < 0)) { 
			_velocity->X(-_velocity->X());
		}

		//this is a tmp fix
		/*if (_oldPosition == _position) {
			_velocity->X(-_velocity->X());
		}*/

		_oldPosition = _position;
	}

	void Patrol::AddToVelocityY(double y) {
		_velocity->Y(_velocity->Y() + y);
	}

	void Patrol::Paint(Graphics* g) {
#ifdef _DEBUG
		GridGraphicTranslator translator = GridGraphicTranslator();
		vector<Tile*> includedTiles = _grid->GetTilesInRectangle(_position, _position + *_size + Vector2D(2));
		g->SetColor(RGB(255, 0, 0));
		for(unsigned int i = 0; i < includedTiles.size(); i++) {
			Tile* t = includedTiles.at(i);
			Vector2D* p = &translator.FromTo(*t->GetPosition());
			includedTiles.at(i)->Paint(g);

			g->DrawRect(Vector2D((int)p->X(), (int)p->Y()), Vector2D((int)p->X() + 16, (int)p->Y() + 16));
		}

		g->SetColor(RGB(0, 255, 0));
		for(unsigned int i = 0; i < CollidingTiles.size(); i++) {
			Tile* t = CollidingTiles.at(i);
			Vector2D* p = &translator.FromTo(*t->GetPosition());
			CollidingTiles.at(i)->Paint(g);
			g->DrawRect(Vector2D((int)p->X(), (int)p->Y()), Vector2D((int)p->X() + 16, (int)p->Y() + 16));
		}
		g->SetColor(RGB(0, 0, 0));
#endif

		static int const kSpriteSize = 32;
		
		int facingOffset = 0;

		if (!_facingRight) {
			facingOffset = kSpriteSize;
		}

		Vector2D offset(0, facingOffset);
		_animation->Render(g, this->_position, offset);
	}
}
