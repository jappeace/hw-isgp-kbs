#include "LoadLevelGameState.h"
#include "Window.h"

namespace isgp {
	LoadLevelGameState::LoadLevelGameState(Window* parent, int levelnr,
			SpriteCache<int>* cache, void(Window::*startLevelCalback)(Level*, Camera*)) {
		_window = parent;
		_cache = cache;
		_levelnr = levelnr;
		_hasDrawn = false;
		_startLevelCalback = startLevelCalback;
		_theme = Theme::CreateTheme(_levelnr);
	}

	LoadLevelGameState::~LoadLevelGameState(void) { }

	void LoadLevelGameState::Paint(Graphics* graphics) {
		if(!_hasDrawn){
			RenderSplashScreen(graphics);
			return;
		}
		pair<Level*, Camera*> loaded = LoadLevel(graphics);
		(_window->*_startLevelCalback)(loaded.first, loaded.second);
	}

	void LoadLevelGameState::KeyDown(int keyCode) { /* ignore keys */ }
	void LoadLevelGameState::KeyUp(int keyCode) { /* ignore */ }
	void LoadLevelGameState::Update(double elapsed) { /* ignore */ }

	void LoadLevelGameState::RenderSplashScreen(Graphics* graphics) {
		// Disable the anoying camera
		graphics->DeleteTranslater();
		_hasDrawn = true;
		string fileName = "..\\tiles\\theme3.bmp";
		graphics->LoadBitmapFile(fileName, false);
		graphics->DrawBitmap(fileName,
			Vector2D(0, 0), Size(800, 600));
	}

	pair<Level*, Camera*> LoadLevelGameState::LoadLevel(Graphics* graphics) {
		// To store results in
		pair<Level*, Camera*> result;

		graphics->SetTranslator(_window->_cam);
		result.first = DefaultlevelFactory().CreateLevel(_levelnr, _theme);
		BackgroundArtist artist = BackgroundArtist(_window->_cam, result.first, /* out */_cache);
		artist.RenderBackground(); // Will handle caching by itself

		graphics->SetTextBackgroundColor(RGB(255, 255, 255));
		result.second = new Camera(result.first->_player, result.first->GetGrid());
		graphics->SetTranslator(result.second);

		// Returns a copy of the pointer pair
		return result;
	}
}
