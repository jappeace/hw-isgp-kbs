#include "InsertNameState.h"

namespace isgp {

	InsertNameState::InsertNameState(Window* window, double elapsedTime)
	{
		_name = "";
		_window = window;
		_elapsedTime = elapsedTime;
		_font = CreateFont(48,0,0,0,FW_DONTCARE,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
			CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY, VARIABLE_PITCH,TEXT("Lucida Console"));
		_totalElapsed = 0.0;
		_showUnderscore = false;
	}


	InsertNameState::~InsertNameState(void)
	{
		DeleteObject(_font);
	}

	void InsertNameState::Paint(Graphics* g) {
		g->SetTextBackgroundColor(RGB(0, 0, 0));
		g->FillRect(Vector2D(0, 0), Size(800, 600),RGB(0, 0, 0));
		g->SetTextColor(RGB(255, 255, 255));
		string nameString = _name;
		if(_showUnderscore) {
			nameString += "_";
		}
		g->DrawStr(Vector2D(330, 200), "Name:", _font);
		g->DrawStr(Vector2D(400 - (_name.length() * 15), 260), nameString, _font);
		g->SetTextBackgroundColor(RGB(255, 255, 255));
	}

	void InsertNameState::Update(double elapsed) {
		_totalElapsed += elapsed;
		if(_totalElapsed > 450) {
			_showUnderscore = !_showUnderscore;
			_totalElapsed = 0;
		}
	}

	void InsertNameState::KeyDown(int keyCode) {

		if(keyCode == VK_BACK) {
			_name = _name.substr(0, _name.length() - 1);
		} else if(keyCode == VK_RETURN) {
			_window->SaveScore(new Highscore(_name, _elapsedTime));
		}  else {
			if(_name.length() <= 20) {
				if(keyCode == 189) {
					_name += "-";
				} else if((keyCode >= 48 && keyCode<= 57) || (keyCode >= 65 && keyCode <= 90) 
					|| (keyCode >= 97 && keyCode <= 122)) {
			
					_name += (char)keyCode;
				}
			}
		}
	}

	void InsertNameState::KeyUp(int keyCode) {
		// Nothing to do here!
	}

}