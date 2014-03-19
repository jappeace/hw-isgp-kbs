#include "LoadLevelGameState.h"

namespace isgp{
	LoadLevelGameState::LoadLevelGameState(Window* parent, int levelnr, SpriteCache<int>* cache) {
		_window = parent;
		_cache = cache;
		_levelnr = levelnr;
		_hasDrawn = false;
	}

	LoadLevelGameState::~LoadLevelGameState(void) {
	}
	void LoadLevelGameState::Paint(Graphics* graphics) {
		// disable the anoying camera
		graphics->SetTranslator(NULL);

		// render splash screen
		graphics->DrawStr(AbstractWindow::WindowSize / Vector2D(2), "Don't forget, this game is awesome");
		graphics->SetTranslator(_window->_cam);

		Level* level = DefaultlevelFactory().CreateLevel(_levelnr);
		BackgroundArtist artist = BackgroundArtist(_window->_cam, level, /* out */_cache);
		artist.RenderBackground(); // wil handle caching by itself

		graphics->SetTextBackgroundColor(RGB(255, 255, 255));
		graphics->SetTranslator(new Camera(level->_player, level->GetGrid()));
	}
	void LoadLevelGameState::KeyDown(int keyCode) { /** ignore keys */}
	void LoadLevelGameState::KeyUp(int keyCode) { /** ignore */}
	void LoadLevelGameState::Update(double elapsed) { /** ignore */}
}