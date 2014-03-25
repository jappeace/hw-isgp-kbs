#include "AbstractWindow.h"

#include "StrConverter.h"
namespace isgp {
//////////////////////////////////////////////////////////////////
// Static Initialisation
//////////////////////////////////////////////////////////////////
// what about avoid global state? Its imposibble now to open 2 windows...
// I used a singleton to prevent this...
static AbstractWindow * g_abstractWindow		= NULL;
HINSTANCE AbstractWindow::_hInstance = GetModuleHandle(NULL);

//////////////////////////////////////////////////////////////////
// Connectivity WIN32 -> Class (yes class not object)
//////////////////////////////////////////////////////////////////
LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return g_abstractWindow->MsgProc(hWnd, uMsg, wParam, lParam);
}

const Size AbstractWindow::WindowSize = Size(800, 600);

//////////////////////////////////////////////////////////////////
// Constructors/Destructors
//////////////////////////////////////////////////////////////////
AbstractWindow::AbstractWindow()
{
	g_abstractWindow = this;
	_hWnd = NULL;
	_dwCreationFlags		= 0L;
	_dwWindowStyle		= WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
	_dwExWindowStyle		= WS_EX_OVERLAPPEDWINDOW;
	_dwCreationFlags		= SW_SHOW;
	_PosX				= CW_USEDEFAULT;	
	_PosY				= CW_USEDEFAULT;	
	_dwCreationWidth		= WindowSize.GetWidth();
	_dwCreationHeight	= WindowSize.GetHeight();
	_hbrWindowColor		= (HBRUSH)(COLOR_WINDOW+1);
	_hIcon				= LoadIcon(_hInstance, (LPCTSTR)"X.ico");
	_strWindowTitle		= _T("Megadude++");
	_hMenu				= NULL; 	
	_graphics			= NULL;
}

AbstractWindow::~AbstractWindow()
{
}

//////////////////////////////////////////////////////////////////
// Functions
//////////////////////////////////////////////////////////////////
int AbstractWindow::Run()
{
	MSG msg = {0};

	while( msg.message!=WM_QUIT )
	{
		
		if( PeekMessage( &msg, NULL, 0U, 0U, PM_REMOVE ) )
		{
			TranslateMessage( &msg );
			DispatchMessage( &msg );
			//GetClientRect
		} 
		else 
		{
			::QueryPerformanceCounter((LARGE_INTEGER*)&_start);
			_stop = _start;
			
			while (((_stop - _start) * 1000) / (double)_freq < _engineThrottle) { //throttle
				::QueryPerformanceCounter((LARGE_INTEGER*)&_stop);
			}
			

			GameLoop(((_stop - _lastUpdate) * 1000) / (double)_freq);
			_lastUpdate = _stop;

			repaint();
		}
	}
	return msg.wParam;
}

HRESULT AbstractWindow::Create()
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 


	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WindowProcedure;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= _hInstance;
	wcex.hIcon			= _hIcon;
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= _hbrWindowColor;
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDR_MENU1);
	wcex.lpszClassName	= _T("Skeleton");
	wcex.hIconSm		= NULL;

	::RegisterClassEx(&wcex);

	_hWnd = ::CreateWindowEx(_dwExWindowStyle,_T("Skeleton"), _strWindowTitle, _dwWindowStyle,
	  _PosX, _PosY, _dwCreationWidth, _dwCreationHeight, NULL, _hMenu, _hInstance, NULL);

	if (!_hWnd)
	{
	  return FALSE;
	}

	_graphics = new WindowGraphics(_hWnd);
	AfterCreate(_hWnd);
	ShowWindow(_hWnd, _dwCreationFlags);
	UpdateWindow(_hWnd);
	_engineThrottle = -1;
	::QueryPerformanceFrequency((LARGE_INTEGER*)&_freq);
	::QueryPerformanceCounter((LARGE_INTEGER*)&_lastUpdate);

	return TRUE;
}

LRESULT AbstractWindow::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc = HDC();

	if (!_hWnd){
		_hWnd = hWnd;
	}

	switch (uMsg) 
	{
		case WM_COMMAND:
			OnCommand(LOWORD(wParam),HIWORD(wParam));
			break;
		case WM_KEYDOWN:
			OnKeyDown(wParam);
			break;

		case WM_KEYUP:
			OnKeyUp(wParam);
			break;

		case WM_PAINT:
			_graphics->BeginRendering();
			OnPaint(_graphics);
			_graphics->EndRendering();
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}

void AbstractWindow::GameLoop(double elapsed) { //elapsed time, in MS
	//update all the game objects now
	
}

void AbstractWindow::repaint() {
	InvalidateRect(_hWnd, 0, FALSE);
}
}