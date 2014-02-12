#ifndef WIN_H
#define WIN_H

#include <windows.h>

class Win
{
public:
	Win();
	virtual ~Win();
	HRESULT Create();
	int Run();
	virtual LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);

protected:
	static HINSTANCE hinstance_;
	HWND hwnd_;
	DWORD pos_x_;
	DWORD pos_y_;
	DWORD window_style_;
	DWORD ex_window_style_;
	DWORD creation_flags_;
	DWORD creation_height_;
	DWORD creation_width_;
	TCHAR *window_title_;
	HBRUSH window_color_;
	HICON icon_;
	HMENU menu_;
	HACCEL accel_table_;
};

#endif
