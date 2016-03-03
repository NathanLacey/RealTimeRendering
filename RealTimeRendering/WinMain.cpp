#include <Windows.h>
//Added Icon file, it creates a resource.h file to load the icon
#include "resource.h"
#include <cstdlib>
#include <string>
#include <cstdint>

// Global variables
// The main window class name.

//TODO: remove global statics and move into a class
static std::wstring szWindowClass = L"RealTimeRenderer";
// The string that appears in the application's title bar.
static std::wstring szTitle = L"Real Time Rendering Project";
HINSTANCE hInst;
const uint32_t screenWidth = 960;
const uint32_t screenHeight = 540;

// Forward declarations of functions included in this code module
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	//Creates a windows class struct that the user can make a description of the window, icon,
	//style, cursor image, etc
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	//wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	// OLD version, i commented it out to show you what i changed it to, to give it an icon file
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass.c_str();
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

	//registers the class, if registration failed
	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			L"Call to RegisterClassEx failed!",
			L"Real Time Rendering Project",
			NULL);

		return 1;
	}
	//When you specify window width and height it adds the borders to it, in rendering we want
	//the exact size of the client area specified, AdjustWindowRect calculates the window size
	//to accurately display the proper client height and width
	RECT r = { 0, 0, static_cast<long>(screenWidth), static_cast<long>(screenHeight) };
	AdjustWindowRect(&r, WS_OVERLAPPEDWINDOW, false);
	uint32_t width = r.right - r.left;
	uint32_t height = r.bottom - r.top;

	uint32_t x = GetSystemMetrics(SM_CXSCREEN) / 2 - width / 2;
	uint32_t y = GetSystemMetrics(SM_CYSCREEN) / 2 - height / 2;

	hInst = hInstance; // Store instance handle in our global variable

					   // The parameters to CreateWindow explained:
					   // szWindowClass: the name of the application
					   // szTitle: the text that appears in the title bar
					   // WS_OVERLAPPEDWINDOW: the type of window to create
					   // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
					   // 500, 100: initial size (width, length)
					   // NULL: the parent of this window
					   // NULL: this application does not have a menu bar
					   // hInstance: the first parameter from WinMain
					   // NULL: not used in this application
	HWND hWnd = CreateWindow(
		szWindowClass.c_str(),
		szTitle.c_str(),
		WS_OVERLAPPEDWINDOW,
		x, y,
		width, height,
		NULL,
		NULL,
		hInstance,
		NULL
		);

	if (!hWnd)
	{
		MessageBox(NULL,
			L"Call to CreateWindow failed!",
			L"Real Time Rendering Project",
			NULL);

		return 1;
	}

	// The parameters to ShowWindow explained:
	// hWnd: the value returned from CreateWindow
	// nCmdShow: the fourth parameter from WinMain
	ShowWindow(hWnd,
		nCmdShow);
	UpdateWindow(hWnd);

	// Main message loop:
	MSG msg = { 0 };
	/*while (GetMessage(&msg, NULL, 0, 0))*/
	//Instead of a GetMessage function we use peek function, if there are no windows messages
	//to handle, the game code will run instead
	while(WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			//TODO:: Add game code here
		}
	}

	return (int)msg.wParam;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}