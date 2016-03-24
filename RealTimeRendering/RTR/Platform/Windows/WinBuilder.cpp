//=====================================================================================
// WindowsClass.h
// Windows Class Object. Designed to encapsulate windows creation and clean 
// the winMain function
//=====================================================================================
#include <RTR/Platform/Windows/WinBuilder.h>
#if RTR_PLATFORM == RTR_PLATFORM_WINDOWS
#include <RTR/GameEngine/RTREngine.h>
namespace RTR
{
	namespace Platform
	{
		namespace Windows
		{
			//=====================================================================================
			// Constructors, Destructors, Copy Constructors and Move Constructors
			//=====================================================================================

			WinBuilder::WinBuilder(HINSTANCE &hInstance, std::wstring appTitle) : 
				AppBuilder(),
				screenWidth_(960),
				screenHeight_(540),
				windowClass_(L"RealTimeRenderer"),
				appTitle_(appTitle),
				hInstance_(hInstance),
				hWnd_(nullptr)
			{

			}

			WinBuilder::~WinBuilder()
			{
			}

			// Forward declarations of functions included in this code module
			LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

			//=====================================================================================
			// Member Functions
			//=====================================================================================
			bool WinBuilder::AdjustSizeAndCreateWindow()
			{
				//When you specify window width and height it adds the borders to it, in rendering we want
				//the exact size of the client area specified, AdjustWindowRect calculates the window size
				//to accurately display the proper client height and width
				RECT r = { 0, 0, static_cast<long>(screenWidth_), static_cast<long>(screenHeight_) };
				AdjustWindowRect(&r, WS_OVERLAPPEDWINDOW, false);
				uint32_t wndWidth = r.right - r.left;
				uint32_t wndHeight = r.bottom - r.top;

				uint32_t wndPosx = GetSystemMetrics(SM_CXSCREEN) / 2 - wndWidth / 2;
				uint32_t wndPosy = GetSystemMetrics(SM_CYSCREEN) / 2 - wndHeight / 2;

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
				hWnd_ = CreateWindow(
					windowClass_.c_str(),
					appTitle_.c_str(),
					WS_OVERLAPPEDWINDOW,
					wndPosx, wndPosy,
					wndWidth, wndHeight,
					NULL,
					NULL,
					hInstance_,
					NULL
					);

				if (!hWnd_)
				{
					MessageBox(NULL,
						L"Call to CreateWindow failed!",
						L"Real Time Rendering Project",
						NULL);
					return false;
				}
				return true;
			}

			bool WinBuilder::Initialize()
			{
				//Creates a windows class struct that the user can make a description of the window, icon,
				//style, cursor image, etc
				WNDCLASSEX wcex;
				wcex.cbSize = sizeof(WNDCLASSEX);
				wcex.style = CS_HREDRAW | CS_VREDRAW;
				wcex.lpfnWndProc = WndProc;
				wcex.cbClsExtra = 0;
				wcex.cbWndExtra = 0;
				wcex.hInstance = hInstance_;
				//wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
				// OLD version, i commented it out to show you what i changed it to, to give it an icon file
				wcex.hIcon = LoadIcon(hInstance_, MAKEINTRESOURCE(IDI_ICON1));
				wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
				wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
				wcex.lpszMenuName = NULL;
				wcex.lpszClassName = windowClass_.c_str();
				wcex.hIconSm = LoadIcon(hInstance_, MAKEINTRESOURCE(IDI_ICON1));

				//registers the class, if registration failed
				if (!RegisterClassEx(&wcex))
				{
					MessageBox(NULL,
						L"Call to RegisterClassEx failed!",
						L"Real Time Rendering Project",
						NULL);

					return false;
				}
				if (!AdjustSizeAndCreateWindow())
				{
					return false;
				}

				// The parameters to ShowWindow explained:
				// hWnd: the value returned from CreateWindow
				// nCmdShow: the fourth parameter from WinMain
				ShowWindow(hWnd_, SW_SHOWDEFAULT);
				UpdateWindow(hWnd_);

				return true;
			}

			int WinBuilder::Run(GameEngine::RTREngine* const engine)
			{
				// Main message loop:
				MSG msg = { 0 };
				/*while (GetMessage(&msg, NULL, 0, 0))*/
				//Instead of a GetMessage function we use peek function, if there are no windows messages
				//to handle, the game code will run instead
				while (WM_QUIT != msg.message)
				{
					if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
					{
						TranslateMessage(&msg);
						DispatchMessage(&msg);
					}
					else
					{
						engine->Update();
						engine->Render();

						//For Diagnostics
						engine->CheckFrameStats();
					}
				}

				return (int)msg.wParam;
			}

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
		}
	}
}
#endif