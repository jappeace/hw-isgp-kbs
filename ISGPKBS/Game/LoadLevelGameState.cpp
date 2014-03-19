#include "LoadLevelGameState.h"
#include "Window.h"

namespace isgp{
	LoadLevelGameState::LoadLevelGameState(Window* parent, int levelnr, SpriteCache<int>* cache, void(Window::*startLevelCalback)(Level*, Camera*)) {
		_window = parent;
		_cache = cache;
		_levelnr = levelnr;
		_hasDrawn = false;
		_startLevelCalback = startLevelCalback;
	}

	LoadLevelGameState::~LoadLevelGameState(void) {
	}
	void LoadLevelGameState::Paint(Graphics* graphics) {
		// disable the anoying camera
		graphics->DeleteTranslater();

		// render splash screen
		graphics->DrawStr(AbstractWindow::WindowSize / Vector2D(2), "Don't forget, this game is awesome");
		graphics->SetTranslator(_window->_cam);

		Level* level = DefaultlevelFactory().CreateLevel(_levelnr);
		BackgroundArtist artist = BackgroundArtist(_window->_cam, level, /* out */_cache);
		artist.RenderBackground(); // wil handle caching by itself

		graphics->SetTextBackgroundColor(RGB(255, 255, 255));
		Camera* cam = new Camera(level->_player, level->GetGrid());
		graphics->SetTranslator(cam);
		(_window->*_startLevelCalback)(level, cam);
	}
	void LoadLevelGameState::KeyDown(int keyCode) { /** ignore keys */}
	void LoadLevelGameState::KeyUp(int keyCode) { /** ignore */}
	void LoadLevelGameState::Update(double elapsed) { /** ignore */}
}