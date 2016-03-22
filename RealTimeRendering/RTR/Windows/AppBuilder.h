//=====================================================================================
// WindowsClass.h
// Windows Class Object. Designed to encapsulate windows creation and clean 
// the winMain function
//=====================================================================================
#pragma once
#include <Windows.h>
#include <cstdlib>
#include <string>
#include <cstdint>
//Added Icon file, it creates a resource.h file to load the icon
#include "resource.h"

namespace RTR
{
	namespace Windows
	{

		class AppBuilder
		{
			//=====================================================================================
			// Constructors, Destructors, Copy Constructors and Move Constructors
			//=====================================================================================
		public:
			AppBuilder() = delete; //no default constructor
			AppBuilder(HINSTANCE &hInstance);
			~AppBuilder();


			//=====================================================================================
			// Variables
			//=====================================================================================
		private:
			uint32_t screenWidth_;
			uint32_t screenHeight_;
			std::wstring windowClass_;
			std::wstring appTitle_;
			HINSTANCE hInstance_;
			HWND hWnd_;

			//=====================================================================================
			// Member Functions
			//=====================================================================================
		private:
			bool AdjustSizeAndCreateWindow();
		public:
			bool Initialize();
			int Run();
		};
	}
}