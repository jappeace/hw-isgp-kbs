#pragma once

namespace isgp {

	// Interface for classes that need to handle keyboardinput.
	class IKeyHandler {
	public:
		virtual void KeyDown(int keyCode) = 0;
		virtual void KeyUp(int keyCode) = 0;
	};
}
