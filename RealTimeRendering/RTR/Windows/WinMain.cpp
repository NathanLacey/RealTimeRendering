//=====================================================================================
// WinMain.cpp
// Main Function. Calls windows 
//=====================================================================================
#include "RTR\Windows\AppBuilder.h"


int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	//Instantiate and initialize windows class
	RTR::Windows::AppBuilder App(hInstance);
	if (!App.Initialize())
	{
		return 1;
	}
	//Run Message Loop
	int msg = App.Run();
	return msg;
}
