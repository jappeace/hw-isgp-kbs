#ifndef WIN_H
#define WIN_H

#include <windows.h>
#include <tchar.h>
#include "resource.h"
#include "Graphics.h"
#include "Size.h"

namespace isgp {
	/** 
	* This class tries to handle all the win32 open window crap.
	* that is initilize a window and capture a event loop.
	
	* Because the event loop expects a function pointer this class is in 
	* practise a singleton. You can initilize more of this class, but the binding
	* from the function pointer to the member function gets overwritten, so the first
	* window's event loop, continues but gets no more messages.
	*/
	class AbstractWindow
	{
	protected:
		static HINSTANCE _hInstance;
		HWND  _hWnd;
		
		DWORD _PosX;
		DWORD _PosY;
		DWORD _dwWindowStyle;
		DWORD _dwExWindowStyle;
		DWORD _dwCreationFlags;
		DWORD _dwCreationHeight;
		DWORD _dwCreationWidth;
		TCHAR * _strWindowTitle;
		HBRUSH _hbrWindowColor;
		HICON  _hIcon;
		HMENU  _hMenu;
		HACCEL _hAccelTable;

		Graphics* _graphics;
		
	public:
		 AbstractWindow();
		 HRESULT Create();
		 int Run();
		 virtual ~AbstractWindow();
		 virtual LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
		 void repaint();
		 static const Size WindowSize;
		 /**
		 * This method forces subclasses to implement the onpaint
		 */
		 virtual void onPaint(Graphics* graphics) = 0; // this also makes the class abstract

		 // don't need to implement these functions
		 virtual void onCommand(int from, int command) {}
		 virtual void onKeyDown(int which){}
		 virtual void onKeyUp(int which){}
	};

}
#endif
