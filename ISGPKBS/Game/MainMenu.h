#pragma once
#include "ListMenu.h"

namespace isgp {
	class MainMenu : public ListMenu
	{
	public:
		~MainMenu();
		void PaintDecoration(Graphics* g);
	};
}
