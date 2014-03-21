#pragma once
#include "IGameState.h"
#include "Window.h"

namespace isgp {
	class Window;

	class InsertNameState :
		public IGameState
	{
	public:
		InsertNameState(Window* window, double elapsedTime);
		~InsertNameState();
		void Paint(Graphics* g) override;
		void Update(double elapsed) override;

		void KeyDown(int keyCode) override;
		void KeyUp(int keyCode) override;

	private:
		string _name;
		double _elapsedTime;
		Window* _window;
		HFONT _font;
		bool _showUnderscore;
		double _totalElapsed;
	};

}