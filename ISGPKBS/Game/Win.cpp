#include "Win.h"
#include <tchar.h>

static Win * g_pWin       = NULL;
HINSTANCE Win::hinstance_ = GetModuleHandle(NULL);

// Connectivity WIN32 -> Class
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return g_pWin->MsgProc(hWnd, uMsg, wParam, lParam);
}

Win::Win()
{
	g_pWin = this;

	this->hwnd_            = NULL;
	this->creation_flags_  = 0L;
	this->window_style_    = WS_OVERLAPPEDWINDOW;
	this->ex_window_style_ = WS_EX_OVERLAPPEDWINDOW;
	this->creation_flags_  = SW_SHOW;
	this->pos_x_           = CW_USEDEFAULT;
	this->pos_y_           = CW_USEDEFAULT;
	this->creation_width_  = CW_USEDEFAULT;
	this->creation_height_ = CW_USEDEFAULT;
	this->window_color_    = (HBRUSH)(COLOR_WINDOW+1);
	this->icon_            = LoadIcon(hinstance_, (LPCTSTR)IDI_APPLICATION);
	this->window_title_    = _T("Win32 OO Skeleton Program...");
	this->menu_            = NULL;
}

Win::~Win()
{
}

int Win::Run()
{
	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, accel_table_, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

	}
	return msg.wParam;
}

HRESULT Win::Create()
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style         = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc   = (WNDPROC)WndProc;
	wcex.cbClsExtra    = 0;
	wcex.cbWndExtra    = 0;
	wcex.hInstance     = hinstance_;
	wcex.hIcon         = icon_;
	wcex.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = window_color_;
	wcex.lpszMenuName  = NULL;
	wcex.lpszClassName = _T("Skeleton");
	wcex.hIconSm       = NULL;

	::RegisterClassEx(&wcex);

	hwnd_ = ::CreateWindowEx(ex_window_style_,
	                         _T("Skeleton"),
	                         window_title_,
	                         window_style_,
	                         pos_x_, pos_y_,
	                         creation_width_, creation_height_,
	                         NULL, menu_, hinstance_, NULL);

	if (!hwnd_)
	{
		return FALSE;
	}

	::ShowWindow(hwnd_, creation_flags_);
	::UpdateWindow(hwnd_);

	return TRUE;
}

LRESULT Win::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	int wmId;
	int wmEvent;

	if (!hwnd_)
		hwnd_ = hWnd;

	switch (uMsg)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}
