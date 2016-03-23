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
#include <RTR/Platform/Platform.h>
#include <RTR/Platform/AppBuilder.h>

#if RTR_PLATFORM == RTR_PLATFORM_WINDOWS

namespace RTR
{
	namespace Platform
	{
		namespace Windows
		{
			class WinBuilder : public AppBuilder
			{
				//=====================================================================================
				// Constructors, Destructors, Copy Constructors and Move Constructors
				//=====================================================================================
			public:
				WinBuilder() = delete; //no default constructor
				WinBuilder(HINSTANCE &hInstance);
				virtual ~WinBuilder() final override;


				//=====================================================================================
				// Variables
				//=====================================================================================
			private:
				uint32_t screenWidth_;
				uint32_t screenHeight_;
				std::wstring windowClass_;
				std::wstring appTitle_;
				HINSTANCE& hInstance_;
				HWND hWnd_;

				//=====================================================================================
				// Member Functions
				//=====================================================================================
			private:
				virtual bool AdjustSizeAndCreateWindow() final override;
			public:
				virtual bool Initialize() final override;
				virtual int Run(GameEngine::RTREngine* const) final override;
			};
		}
	}
}
#endif