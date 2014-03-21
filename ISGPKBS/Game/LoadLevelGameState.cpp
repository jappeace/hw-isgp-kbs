#include "LoadLevelGameState.h"
#include "Window.h"

namespace isgp{
	LoadLevelGameState::LoadLevelGameState(Window* parent, int levelnr, SpriteCache<int>* cache, void(Window::*startLevelCalback)(Level*, Camera*)) {
		_window = parent;
		_cache = cache;
		_levelnr = levelnr;
		_hasDrawn = false;
		_startLevelCalback = startLevelCalback;
		_loadedLevel = NULL;
		_loadedCamera = NULL;
	}

	LoadLevelGameState::~LoadLevelGameState(void) {
	}

	void LoadLevelGameState::Paint(Graphics* graphics) {

		if(!_hasDrawn){
			RenderSplashScreen(graphics);
			return;
		}
		pair<Level*, Camera*> loaded = LoadLevel(graphics);
		_loadedLevel = loaded.first;
		_loadedCamera = loaded.second;
	}

	void LoadLevelGameState::KeyDown(int keyCode) { /** ignore keys */}
	void LoadLevelGameState::KeyUp(int keyCode) { /** ignore */}

	void LoadLevelGameState::Update(double elapsed) {
		if (_loadedCamera == NULL || _loadedLevel == NULL) {
			return;
		}

		(_window->*_startLevelCalback)(_loadedLevel, _loadedCamera);
	}

	void LoadLevelGameState::RenderSplashScreen(Graphics* graphics){

		// disable the anoying camera
		graphics->DeleteTranslater();
		_hasDrawn = true;
		// render splash screen
		graphics->DrawStr(AbstractWindow::WindowSize / Vector2D(2.5,2.2), "Loading level");
		graphics->DrawStr(AbstractWindow::WindowSize / Vector2D(3,2), "Don't forget, this game is awesome");
	}

	pair<Level*, Camera*> LoadLevelGameState::LoadLevel(Graphics* graphics){
		// to store results in
		pair<Level*, Camera*> result;

		// Load common level assets
		graphics->LoadBitmapFile("../tiles/jumpPad.bmp");
		graphics->LoadBitmapFile("../tiles/link.bmp");
		graphics->LoadBitmapFile("../tiles/megaman.bmp");
		graphics->LoadBitmapFile("../tiles/boo.bmp");
		graphics->LoadBitmapFile("../tiles/toad.bmp");

		// Load Level
		graphics->SetTranslator(_window->_cam);
		Theme* theme = Theme::CreateTheme(_levelnr);
		theme->LoadContent(graphics);
		result.first = DefaultlevelFactory().CreateLevel(_levelnr, theme);
		BackgroundArtist artist = BackgroundArtist(_window->_cam, result.first, /* out */_cache);
		artist.RenderBackground(); // wil handle caching by itself

		graphics->SetTextBackgroundColor(RGB(255, 255, 255));
		result.second = new Camera(result.first->_player, result.first->GetGrid());
		graphics->SetTranslator(result.second);

		// returns a copy of the pointer pair
		return result;
	}
}