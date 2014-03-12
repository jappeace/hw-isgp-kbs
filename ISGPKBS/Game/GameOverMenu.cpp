#include "GameOverMenu.h"

namespace isgp {
	void GameOverMenu::Paint(Graphics* g) {
		g->DrawStr(Vector2D(100, 100), "NICE MAYMAY", strlen("NICE MAYMAY"));
	}
}
