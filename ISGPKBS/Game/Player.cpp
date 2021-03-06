#include "gravitybehaviour.h"
#include "Player.h"
#include "CollisionDetection.h"
#include "Sound.h"
#include "PlayingGameState.h"

namespace isgp{
const Size Player::InitSize(32, 32);
	Player::Player(Vector2D position) {
		_maxVel = 350;
		_accel = 2200;
		_deAccel = 1100;
		_isAlive = true;

		_position = GridGraphicTranslator().FromTo(position);
		_velocity = new Vector2D();
		_leftKey = false;
		_rightKey = false;
		_upKey = false;
		_spaceKey = false;
		_size = new Size(Player::InitSize);
		_behaviours = new vector<IBehaviour*>();
		_behaviours->push_back(new GravityBehaviour(this));
		_has_gravity_boots = false;
	
		_facingRight = true;
		_animation = new Animation("tiles/megaman.bmp", (Size) *_size, 4, 200);
	}

	Player::~Player(void) {
		// Delete references in vector
		for (auto behaviour = _behaviours->begin(); behaviour != _behaviours->end(); ++behaviour) {
			//delete behaviour;
		}
		// Delete vector
		delete _behaviours;
		delete _size;
		delete _velocity;
		delete _animation;
	}

	void Player::Set_has_gravity_boots(bool hasBoots) {
		this->_has_gravity_boots = hasBoots;
	}

	bool Player::Get_has_gravity_boots() {
		return this->_has_gravity_boots;
	}

	void Player::Update(const double milisec) {
		double elapsed = milisec / 1000;

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
			_velocity->X(_velocity->X() - _deAccel * elapsed);
		}
		
		// no wandering
		if (!_leftKey && !_rightKey && (collision & Down) && _velocity->X() < 100 && _velocity->X() > -100) {
			_velocity->X(0);
		}

		//behaviors
		for (unsigned int i = 0; i < _behaviours->size(); ++i) {
			_behaviours->at(i)->Update(milisec);
		}
		Move((*_velocity) * Vector2D(elapsed));
		if((collision & Down && _velocity->Y() > 0) || (collision & Up && _velocity->Y() < 0)) { 
			_velocity->Y(0);
		}
		if((collision & Right && _velocity->X() > 0) || (collision & Left && _velocity->X() < 0)) { 
			_velocity->X(0);
		}

		if(_upKey && (collision & Down)) {
			Sound().Play(JUMP);
			_velocity->Y(-650);
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

		if (GridGraphicTranslator().FromTo(*_grid->GetSize()).Y() - 100 < _position.Y()){
			//_velocity->Y(0);
			//_position.Y(GridGraphicTranslator().FromTo(*_grid->GetSize()).Y() - 101);
		}
	}
	
	void Player::AddToVelocityY(double y) {
		_velocity->Y(_velocity->Y() + y);
	}

	void Player::Paint(Graphics* g) {
	if(PlayingGameState::_debugMode)
	{
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
		g->DrawStr(Vector2D(10, 55), "Collision:");
		g->DrawStr(Vector2D(10, 70), collision & Up ? "Up: true" : "Up: false");
		g->DrawStr(Vector2D(10, 85), collision & Down ? "Down: true" : "Down: false");
		g->DrawStr(Vector2D(10, 100), collision & Left ? "Left: true" : "Left: false");
		g->DrawStr(Vector2D(10, 115), collision & Right ? "Right: true" : "Right: false");

		// Facing info
		if (_facingRight) {
			g->DrawRect(Vector2D(_position.X() + 32, _position.Y() + 8), Vector2D(_position.X() + 40, _position.Y() + 16));
		} else {
			g->DrawRect(Vector2D(_position.X(), _position.Y() + 8), Vector2D(_position.X() - 8, _position.Y() + 16));
		}
	}
		static int const kSpriteSize = 32;

		// Check the facing of the player
		int facingOffset = 0;
		if (!_facingRight) {
			facingOffset = kSpriteSize;
		}

		// Check the upgrades of the palyer
		int armorUpgradeOffset = 0; // Offset which maps to the correct texture for the given upgrades
		if(this->_has_gravity_boots) {
			armorUpgradeOffset = 96;
		}

		Vector2D posFix = _position;
		posFix.Y(posFix.Y() + 3);
		
		// Draw
		if (_velocity->Y() != 0.0) {
			// In the air
			Vector2D offset((2 * kSpriteSize) + facingOffset, 2 * kSpriteSize + armorUpgradeOffset);
			g->DrawBitmap("tiles/megaman.bmp", posFix, offset, Size(kSpriteSize, kSpriteSize));
		} else if (!_leftKey && !_rightKey) {
			// Standing still on the ground
			Vector2D offset(facingOffset, 2 * kSpriteSize + armorUpgradeOffset);
			g->DrawBitmap("tiles/megaman.bmp", posFix, offset, Size(kSpriteSize, kSpriteSize));
		} else {
			// Moving
			Vector2D offset(0, facingOffset + armorUpgradeOffset);
			_animation->Render(g, posFix, offset);
		}
if(PlayingGameState::_debugMode)
{
		g->DrawStaticRect(Vector2D(395, 395), Vector2D(405, 405));
}
	}

	// Check if the player is alive.
	bool Player::IsAlive() {
		return _isAlive;
	}

	// Kill the player by setting it's Alive status to false.
	void Player::Kill() {
		Sound sound;
		sound.Play(END_LOSE);
		_isAlive = false;
	}
}
