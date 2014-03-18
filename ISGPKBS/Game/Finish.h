#pragma once
#include "Entity.h"
#include "Animation.h"
#include "Player.h"
namespace isgp {
	class Finish :
		public Entity
	{
	public:
		Finish(Vector2D, Player*);
		~Finish(void);
		void Paint(Graphics*) override;
		void Update(const double) override;
		Vector2D GetPosition();
	private:
		Vector2D _animationOffset;
		bool _lastWasLeft;
		Player* _player;
		Vector2D offset;
		Animation* _animation;
	};
}
