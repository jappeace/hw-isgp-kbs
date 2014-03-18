#pragma once
#include "Entity.h"
#include "Animation.h"
namespace isgp {
	class Finish :
		public Entity
	{
	public:
		Finish(Vector2D);
		~Finish(void);
		void Paint(Graphics*) override;
		void Update(const double) override;
		Vector2D GetPosition();
	private:
		Vector2D offset;
		Animation* _animation;
	};
}
