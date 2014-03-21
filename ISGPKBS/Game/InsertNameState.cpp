#include "InsertNameState.h"

namespace isgp {

	InsertNameState::InsertNameState(Window* window, double elapsedTime)
	{
		_name = "";
		_window = window;
		_elapsedTime = elapsedTime;
	}


	InsertNameState::~InsertNameState(void)
	{
	}

	void InsertNameState::Paint(Graphics* g) {
		g->DrawStr(Vector2D(360, 390), _name);
	}

	void InsertNameState::Update(double elapsed) {
	}

	void InsertNameState::KeyDown(int keyCode) {
		if(keyCode == VK_BACK) {
			_name = _name.substr(0, _name.size() - 2);
		} else if(keyCode == VK_RETURN) {
			_window->SaveScore(new Highscore(_name, _elapsedTime));
		} else if(keyCode > 32 && keyCode < 126) {
			_name += (char)keyCode;
		}
	}

	void InsertNameState::KeyUp(int keyCode) {
		// Nothing to do here!
	}

}