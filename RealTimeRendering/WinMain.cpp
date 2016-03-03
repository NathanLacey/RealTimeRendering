#include "WindowsClass.h"


int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	WindowsClass App(hInstance);
	if (!App.Initialize())
	{
		return 1;
	}
	int msg = App.Run();
	return msg;
}
