#pragma once
#include "IGameState.h"
#include "Window.h"
namespace isgp {
	class Window;

	class GameCompletedGameState : public IGameState
	{
	public:
		GameCompletedGameState(Window* window);
		~GameCompletedGameState(void);

		void Paint(Graphics* g) override;
		void Update(double elapsed) override;

		void KeyDown(int keyCode) override;
		void KeyUp(int keyCode) override;
	private:
		Window* _window;
		HBRUSH _brush;
	};
}