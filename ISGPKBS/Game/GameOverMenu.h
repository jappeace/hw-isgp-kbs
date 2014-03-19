#pragma once

#include "ListMenu.h"
#include <vector>

namespace isgp {
	class GameOverMenu : public ListMenu {
	public:
		~GameOverMenu();
		void PaintDecoration(Graphics* g);
	};
}
