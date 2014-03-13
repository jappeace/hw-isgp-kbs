#include "gravitybehaviour.h"
#include "Player.h"
#include "CollisionDetection.h"
namespace isgp{
const Size Player::InitSize(32, 32);
	Player::Player(Vector2D position) {
		_maxVel = 500;
		_accel = 220;
		_deAccel = 110;

		_position = position;
		_velocity = new Vector2D();
		_leftKey = false;
		_rightKey = false;
		_upKey = false;
		_spaceKey = false;
		_size = new Size(Player::InitSize);
		_behaviours = new vector<IBehaviour*>();
		_behaviours->push_back(new GravityBehaviour(this));
		
		_animation = new Animation(".\\tiles\\megaman.bmp", (Size) *_size, 4, 200);
	}

	Player::~Player(void) {
		// Delete references in vector
		for (IBehaviour* behaviour = _behaviours->front(); behaviour != _behaviours->back(); ++behaviour) {
			delete behaviour;
		}
		// Delete vector
		delete _behaviours;
		delete _size;
		delete _velocity;
		delete _animation;
	}

	void Player::Update(const double milisec) {
		double elapsed = milisec / 1000;

		collision = CheckCollision();

		if(_leftKey && _velocity->X() > -_maxVel) {
			if(collision & Down){
				_velocity->X(_velocity->X() - (_accel * elapsed));
			} else {
				_velocity->X(_velocity->X() - (_deAccel * elapsed));
			}
		} else if(_velocity->X() < 0 && (collision & Down)) {
			_velocity->X(_velocity->X() + _deAccel * elapsed);
		}

		if(_rightKey && _velocity->X() < _maxVel) {
			if(collision & Down) {
				_velocity->X(_velocity->X() + _accel * elapsed);
			} else {
				_velocity->X(_velocity->X() + _deAccel * elapsed);
			}
		} else if(_velocity->X() > 0 && (collision & Down)) {
			_velocity->X(_velocity->X() + _deAccel * elapsed);
		}
		
		// no wandering
		if (!_leftKey && !_rightKey && (collision & Down) && _velocity->X() < 20 && _velocity->X() > -20) {
			_velocity->X(0);
		}

		for (unsigned int i = 0; i < _behaviours->size(); ++i) {
			_behaviours->at(i)->Update(milisec);
		}
		if((collision & Down && _velocity->Y() > 0) || (collision & Up && _velocity->Y() < 0)) { 
			_velocity->Y(0);
		}
		if((collision & Right && _velocity->X() > 0) || (collision & Left && _velocity->X() < 0)) { 
			_velocity->X(0);
		}
		_position += (*_velocity) * Vector2D(elapsed);

		if(_upKey && (collision & Down)) {
			_velocity->Y(-220);
		}

	}

	void Player::MoveTo(int x, int y) {
	}
	
	void Player::AddToVelocityY(double y) {
		_velocity->Y(_velocity->Y() + y);
	}

	void Player::Paint(Graphics* g) {
		_graphics = g;
		
#ifdef _DEBUG
		GridGraphicTranslator translator = GridGraphicTranslator();
			vector<Tile*> includedTiles = _grid->GetTilesInRectangle(_position, _position + *_size);

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

			g->DrawStr(Vector2D(10, 40), collision & Up ? "Up: true" : "Up: false");
g->DrawStr(Vector2D(10, 55), collision & Down ? "Down: true" : "Down: false");
g->DrawStr(Vector2D(10, 70), collision & Left ? "Left: true" : "Left: false");
g->DrawStr(Vector2D(10, 85), collision & Right ? "Right: true" : "Right: false");
#endif
		_graphics->DrawRect(_position, _position + *_size);
#ifdef _DEBUG
		_graphics->DrawStaticRect(Vector2D(395, 395), Vector2D(405, 405));
#endif

		
	}
}
