//=====================================================================================
// WinMain.cpp
// Main Function. Calls windows 
//=====================================================================================
#include "WindowsClass.h"



int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	//Instantiate and initialize windows class
	WindowsClass App(hInstance);
	if (!App.Initialize())
	{
		return 1;
	}
	//Run Message Loop
	int msg = App.Run();
	return msg;
}
