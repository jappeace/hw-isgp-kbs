// bitmap.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "bitmap.h"
#include "Block.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_BITMAP, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_BITMAP));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_BITMAP));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_BITMAP);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
const int GAME_TIMER_ID = 1337;
const int GAME_TIMER_INTERVAL = 1000 / 50; //50 cycles per second
HBITMAP hCharacter = NULL;
HBRUSH hRectangleBrush = CreateSolidBrush(RGB(0,0,0));

RECT rect;

int positionX = 100;
int positionY = 100;
bool left = false;
bool right = false;
bool up = false;
bool down = false;
int xVel = 0;
int yVel = 0;
Block *block = new Block(100,100);

void GameLogic() {
			//if (up && yVel > -10){ yVel -= 1; }
		//else if (yVel < 0){ yVel++; }
		//if (down && yVel < 10){ yVel += 1; }
		//else if (yVel > 0){ yVel--; }

		if (left && xVel > -10){ xVel -= 1; }
		else if (xVel < 0){ xVel++; }
		if (right && xVel < 10){ xVel += 1; }
		else if (xVel > 0){ xVel--; }

		positionY += yVel;
		positionX += xVel;
		
		if (positionY < 0) { positionY = 0; }
		if (positionY > 520) { positionY = 520; }
		if (positionX < 0) { positionX = 0; }
		if (positionX > 760) { positionX = 760; }

		if (positionY < 520) { yVel += 1; }
		else { yVel = 0; }
		if (up && positionY == 520) { yVel = -12; }
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	static HDC		hdcBackBuffer;
	static HBITMAP	hBitmap;
	static HBITMAP	hOldBitmap;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;

	case WM_KEYDOWN:
		if (wParam == VK_RIGHT){
			right = true;
		}
		if (wParam == VK_LEFT){
			left = true;
		}
		if (wParam == VK_UP){
			up = true;
		}
		if (wParam == VK_DOWN){
			down = true;
		}
		break;

	case WM_KEYUP:
		if (wParam == VK_RIGHT){
			right = false;
		}
		if (wParam == VK_LEFT){
			left = false;
		}
		if (wParam == VK_UP){
			up = false;
		}
		if (wParam == VK_DOWN){
			down = false;
		}

		break;
	case WM_CREATE:
		
		hCharacter = (HBITMAP)LoadImage(hInst, L"c:\\test.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		SetWindowPos(hWnd, HWND_TOP, 100, 100, 800, 600, SWP_ASYNCWINDOWPOS);
		GetClientRect(hWnd, &rect);

		//create a memory device context
		hdcBackBuffer = CreateCompatibleDC(NULL);

		//get the DC for the front buffer
		hdc = GetDC(hWnd);

		hBitmap = CreateCompatibleBitmap(hdc,
			800,
			600); //nog waardes halen uit rect


		//select the bitmap into the memory device context
		hOldBitmap = (HBITMAP)SelectObject(hdcBackBuffer, hBitmap);

		//don't forget to release the DC
		ReleaseDC(hWnd, hdc); 

		::SetTimer(hWnd, GAME_TIMER_ID, GAME_TIMER_INTERVAL, NULL);
		break;

	case WM_PAINT: {

		hdc = BeginPaint(hWnd, &ps);

		BitBlt(hdcBackBuffer,
			0,
			0,
			800,
			600,
			NULL,
			NULL,
			NULL,
			WHITENESS);

		SelectObject(hdcBackBuffer, hRectangleBrush);

		// Draw the rectangle on the back buffer
		Rectangle(hdcBackBuffer, positionX, positionY, positionX + 20, positionY + 20);


		//now blit backbuffer to front
		BitBlt(ps.hdc, 0, 0, 800, 600, hdcBackBuffer, 0, 0, SRCCOPY);
		EndPaint(hWnd, &ps);
		break;
	}

	case WM_TIMER:
		switch(wParam) {
		case GAME_TIMER_ID:
			GameLogic();
			InvalidateRect(hWnd, &rect, true);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:

		return DefWindowProc(hWnd, message, wParam, lParam);

	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
