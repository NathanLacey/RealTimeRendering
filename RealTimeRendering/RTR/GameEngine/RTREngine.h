//=====================================================================================
// GameEngine.h
// Where the game code will reside, this class will load the renderer, and manage
// the different game objects. This class ensures the different components run and
// initialize in the correct order.
//=====================================================================================
#pragma once
#include <memory>

#include <RTR/Platform/Platform.h>
#include <RTR/Platform/AppBuilder.h>
#include <RTR/Rendering/Renderer.h>
#if RTR_PLATFORM == RTR_PLATFORM_WINDOWS
#include <RTR/Platform/Windows/WinBuilder.h>
#endif

class Renderer;
namespace RTR
{
	namespace GameEngine
	{
		class RTREngine
		{
		public:
			RTREngine() = default;
			~RTREngine() = default;
#if RTR_PLATFORM == RTR_PLATFORM_WINDOWS
			RTREngine(HINSTANCE &hInstance);
#endif
			bool Initialize();
			void Shutdown();
			int Run();
		private:
			std::unique_ptr<RTR::Platform::AppBuilder> app_;
			RTR::Rendering::Renderer *renderer_;
		};
	}
}