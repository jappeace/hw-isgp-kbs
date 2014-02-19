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

HBITMAP hBitmap = NULL;
HBITMAP hBitmap2 = NULL;
int positionX = 384;
int positionY = 520;
bool left = false;
bool right = false;
bool up = false;
bool down = false;
float xVel = 0;
float yVel = 0;
Block *block = new Block(100,100);
float camX = 348;
float camY = 400;
bool collision = false;
int camDirection = 0;
float camFix = 0;
bool fixCam = false;

void UpdateCamFix(){
	if (camDirection == 2){ camFix = camFix + (-200 - camFix) * 0.1; }
	else if (camDirection == 1) { camFix = camFix + (200 - camFix) * 0.05; }
	else { camFix = camFix + (0 - camFix) * 0.2; }
}

void UpdateCam(){
	if (fixCam){
		UpdateCamFix();
	}else{
		camFix = 0;
	}
	camX = camX + ((positionX - camX) + camFix) * 0.1;
	camY = camY + (positionY - camY) * 0.1;
}

int GetDrawPositionX(int x){
	return (x - camX) + 384;
}

int GetDrawPositionY(int y){
	return (y - camY) + 400;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

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
			fixCam = true;
		}
		if (wParam == VK_SPACE){
			fixCam = false;
		}
		if (wParam == VK_LSHIFT){
			fixCam = true;
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
		hBitmap = (HBITMAP)LoadImage(hInst, L"c:\\test.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap2 = (HBITMAP)LoadImage(hInst, L"c:\\block.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		SetWindowPos(hWnd, HWND_TOP, 100, 100, 800, 600, SWP_ASYNCWINDOWPOS);
		break;
	case WM_PAINT:
		PAINTSTRUCT 	ps;
    	HDC 			hdc;
    	BITMAP 			bitmap;
    	HDC 			hdcMem;
        HGDIOBJ 		oldBitmap;
		
		hdc = BeginPaint(hWnd, &ps);
		hdcMem = CreateCompatibleDC(hdc);
		
		oldBitmap = SelectObject(hdcMem, hBitmap);
		GetObject(hBitmap, sizeof(bitmap), &bitmap);
        //BitBlt(hdc, 384, 400, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);
        //BitBlt(hdc, positionX, positionY, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);
		BitBlt(hdc, GetDrawPositionX(positionX), GetDrawPositionY(positionY), bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);
		
        oldBitmap = SelectObject(hdcMem, hBitmap2);
		GetObject(hBitmap2, sizeof(bitmap), &bitmap);
		BitBlt(hdc, GetDrawPositionX(500), GetDrawPositionY(552), bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);
		BitBlt(hdc, GetDrawPositionX(400), GetDrawPositionY(552), bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);
		BitBlt(hdc, GetDrawPositionX(300), GetDrawPositionY(552), bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);

		MoveToEx(hdc, GetDrawPositionX(0), GetDrawPositionY(0), NULL);
		LineTo(hdc, GetDrawPositionX(0), GetDrawPositionY(552));
		LineTo(hdc, GetDrawPositionX(800), GetDrawPositionY(552));
		LineTo(hdc, GetDrawPositionX(800), GetDrawPositionY(0));

        SelectObject(hdcMem, oldBitmap);
        DeleteDC(hdcMem);

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		//if (up && yVel > -10){ yVel -= 1; }
		//else if (yVel < 0){ yVel++; }
		//if (down && yVel < 10){ yVel += 1; }
		//else if (yVel > 0){ yVel--; }

		if (left && xVel > -10){ 
			if (collision){ xVel -= 1; }else{ xVel -= 0.5; }
		}
		else if (xVel < 0 && collision){ xVel += 0.5; }
		if (right && xVel < 10){
			if (collision){ xVel += 1; }else{ xVel += 0.5; }
		}
		else if (xVel > 0 && collision){ xVel -= 0.5; }

		positionY += yVel;
		positionX += xVel;
		
		if (xVel >= 9){ camDirection = 1; }
		else if (xVel <= -9){ camDirection = 2; }
		else { camDirection = 0; }
		
		if (positionY < 0) { positionY = 0; }
		if (positionY > 520) { positionY = 521; collision = true; } else { collision = false; }
		if (positionX < 0) { positionX = 0; }
		if (positionX > 768) { positionX = 768; }

		if (positionY < 521) { yVel += 1; }
		else { yVel = 0; }
		if (up && positionY >= 520) { yVel = -12; }

		UpdateCam();

		RECT rect;
		GetClientRect(hWnd, &rect);
		InvalidateRect(hWnd, &rect, true);
		//UpdateWindow(hWnd);

		Sleep(20);  

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
