#pragma once
#include "Window.h"
#include "BackgroundArtist.h"
#include "DefaultLevelFactory.h"
namespace isgp{
	class LoadLevelGameState : IGameState {
	public:
		LoadLevelGameState(Window* parent, int levelnr, SpriteCache<int>* cache, void(Window::*startLevel)());
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
		void(Window::*_startLevelmfp)();
	};


}