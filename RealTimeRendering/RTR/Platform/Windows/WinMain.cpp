//=====================================================================================
// WinMain.cpp
// Main Function. Calls windows 
//=====================================================================================
#include <RTR/GameEngine/RTREngine.h>
#if RTR_PLATFORM == RTR_PLATFORM_WINDOWS

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	//Instantiate and initialize windows class
	RTR::GameEngine::RTREngine Game(hInstance);
	if (!Game.Initialize())
	{
		return 1;
	}
	//Run Message Loop
	int msg = Game.Run();
	Game.Shutdown();
	return msg;
}
#endif
