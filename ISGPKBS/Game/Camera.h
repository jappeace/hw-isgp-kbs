#pragma once

#include "Player.h"
#include "GridGraphicTranslator.h"

namespace isgp{
	class Camera : public ITranslator {
	public:
		Camera(Player*);
		~Camera(void);
		void Update(double);
		Vector2D FromTo(Vector2D) override;
		Vector2D ToFrom(Vector2D) override;
	private:
		Player* _player;
		Vector2D _position;
		int _direction;
		double _camFix;
	};
}
