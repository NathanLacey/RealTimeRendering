//=====================================================================================
// RTREngine.h
// Where the game code will reside, this class will load the renderer, and manage
// the different game objects. This class ensures the different components run and
// initialize in the correct order.
//=====================================================================================
#pragma once
#include <memory>
#include <string>
#include <RTR/Platform/Platform.h>
#include <RTR/Rendering/Renderer.h>
#include <RTR/Platform/AppBuilder.h>
#include <RTR/Utilities/Timer.h>

#if RTR_PLATFORM == RTR_PLATFORM_WINDOWS
#include <Windows.h>
#endif

namespace RTR
{
	struct AppData
	{
		uint32_t screenWidth;
		uint32_t screenHeight;
		std::wstring appTitle;
	};
	namespace GameEngine
	{
		class RTREngine
		{
			//=====================================================================================
			// Constructors, Destructors, Copy Constructors and Move Constructors
			//=====================================================================================
		public:
			RTREngine() = default;
			~RTREngine() = default;
#if RTR_PLATFORM == RTR_PLATFORM_WINDOWS
			RTREngine(HINSTANCE &hInstance, AppData &appData);
#endif

			//=====================================================================================
			// Member Variables
			//=====================================================================================
		private:
			std::unique_ptr<Platform::AppBuilder> app_;
			std::unique_ptr<Rendering::Renderer> renderer_;
			std::wstring appTitle_;
			uint32_t screenWidth_;
			uint32_t screenHeight_;
			Utilities::Timer gameTimer_;
#if RTR_PLATFORM == RTR_PLATFORM_WINDOWS
			HINSTANCE hInstance_;
#endif
			//=====================================================================================
			// Member Functions
			//=====================================================================================
		public:
			bool Initialize();
			void Shutdown();
			int Run();
			void Update();
			void Render();
			void CheckFrameStats();

			std::wstring GetAppTitle() const { return appTitle_; }
			uint32_t GetScreenWidth() const { return screenWidth_; }
			uint32_t GetScreenHeight() const { return screenHeight_; }
#if RTR_PLATFORM == RTR_PLATFORM_WINDOWS
			HINSTANCE GetInstance() const { return hInstance_; }
#endif
		};
	}
}