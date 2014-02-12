#pragma once

#include <cstdlib>
#include "AbstractWindow.h"
#include "resource2.h"
#include "Level.h"

namespace isgp {
	class Window : public AbstractWindow {
	public:
		Window();
		~Window();
		void onPaint(Graphics* graphics);
		void onCommand(int from, int command);
		LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
	private:
		Level* _level;
	};
}
