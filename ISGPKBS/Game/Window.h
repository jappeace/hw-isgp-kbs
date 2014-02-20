#pragma once

#include <cstdlib>
#include "AbstractWindow.h"
#include "resource2.h"
#include "Level.h"
#include "WorldBlock.h"

namespace isgp {
	class Window : public AbstractWindow {
	public:
		Window();
		~Window();
		void OnPaint(Graphics* graphics);
		void OnCommand(int from, int command);
		LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
		void OnKeyDown(int which) override;
	private:
		Level* _level;
	};
}
