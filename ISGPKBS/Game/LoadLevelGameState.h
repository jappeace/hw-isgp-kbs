#pragma once
#include "BackgroundArtist.h"
#include "DefaultLevelFactory.h"
#include "IGameState.h"
namespace isgp{
	class Window;
	class LoadLevelGameState : public IGameState {
	public:
		LoadLevelGameState(Window* parent, int levelnr, SpriteCache<int>* cache, void(Window::*startLevelCalback)(Level* level, Camera*));
		
		~LoadLevelGameState(void);
		void Update(double elapsed) override;
		void Paint(Graphics* g) override;
		void KeyDown(int keyCode) override;
		void KeyUp(int keyCode) override;
	private:
		Window* _window;
		SpriteCache<int>* _cache;
		int _levelnr;
		bool _hasDrawn;
		Level* _loadedLevel;
		Camera* _loadedCamera;
		void(Window::*_startLevelCalback)(Level* level, Camera*);
		void RenderSplashScreen(Graphics* graphics);
		pair<Level*, Camera*> LoadLevel(Graphics* graphics);
	};


}