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
		_loadedLevel = NULL;
		_loadedCamera = NULL;
		_theme = Theme::CreateTheme(_levelnr);
	}

	LoadLevelGameState::~LoadLevelGameState(void) { }

	void LoadLevelGameState::Paint(Graphics* graphics) {
		if(!_hasDrawn){
			RenderSplashScreen(graphics);
			return;
		}
		pair<Level*, Camera*> loaded = LoadLevel(graphics);
		_loadedLevel = loaded.first;
		_loadedCamera = loaded.second;
	}

	void LoadLevelGameState::Update(double elapsed) {
		if (_loadedCamera == NULL || _loadedLevel == NULL) {
			return;
		}

		(_window->*_startLevelCalback)(_loadedLevel, _loadedCamera);
	}

	void LoadLevelGameState::KeyDown(int keyCode) { /* ignore keys */ }
	void LoadLevelGameState::KeyUp(int keyCode) { /* ignore */ }

	void LoadLevelGameState::RenderSplashScreen(Graphics* graphics) {
		// Disable the anoying camera
		graphics->DeleteTranslater();
		_hasDrawn = true;
		string fileName = _theme->GetLoadPath();
		graphics->LoadBitmapFile(fileName, false);
		graphics->DrawBitmap(fileName,
			Vector2D(0, 0), Size(800, 600));
	}

	pair<Level*, Camera*> LoadLevelGameState::LoadLevel(Graphics* graphics) {
		// To store results in
		pair<Level*, Camera*> result;

		// Load common level assets
		graphics->LoadBitmapFile("../tiles/jumpPad.bmp");
		graphics->LoadBitmapFile("../tiles/link.bmp");
		graphics->LoadBitmapFile("../tiles/megaman.bmp");
		graphics->LoadBitmapFile("../tiles/boo.bmp");
		graphics->LoadBitmapFile("../tiles/toad.bmp");

		// Load Level
		graphics->SetTranslator(_window->_cam);
		result.first = DefaultlevelFactory().CreateLevel(_levelnr, _theme);
		result.second = new Camera(result.first->_player, result.first->GetGrid());
		BackgroundArtist artist = BackgroundArtist(result.second, result.first, /* out */_cache);
		_theme->LoadContent(graphics);
		artist.RenderBackground(); // Will handle caching by itself

		graphics->SetTextBackgroundColor(RGB(255, 255, 255));
		graphics->SetTranslator(result.second);

		// Returns a copy of the pointer pair
		return result;
	}
}
