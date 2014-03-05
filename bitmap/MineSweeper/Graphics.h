#pragma once
#include <windows.h>
#include <string>
#include "Point.h"
using namespace std;
namespace isgp{
	/** this class tries to tackle the beast called win32 espacialy the rendering part
	* whenever you use a win32 drawing function you should just try to implement it in this class
	* to make usage easier for other teammembers
	*/
	class Graphics
	{
	public:
		Graphics(void);
		~Graphics(void);
		void setHDC(HDC* hdc);
		void drawStr(Point& position, string str);
		void drawStr(Point& position, const char* str, int length);
		void setTextColor(COLORREF color);
		void setTextBackgroundColor(COLORREF color);
		void drawRect(Point& one, Point& two);
		void drawRect(int xone, int yone, int xtwo, int ytwo);
	private:
		/**
		* win 32 uses somthing called a HDC, which is a handle to the 
		* 'device context'. handle == pointer (probably)
		* putting it in the class allows all drawing functions to call this after setting it once
		* in the abstractWindow
		*/
		HDC* _hdc;
	};
}