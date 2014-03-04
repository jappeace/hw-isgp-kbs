#pragma once

#include "Player.h"
#include "GridGraphicTranslator.h"

namespace isgp{
	class Camera : public ITranslator {
	public:
		Camera(Player*);
		~Camera(void);
		void Update();
		Point FromTo(Point p) override;
		Point ToFrom(Point p) override;
	private:
		Player* _player;
		Point _position;
		int _direction;
		double _camFix;
	};
}
