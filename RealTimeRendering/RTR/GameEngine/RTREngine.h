//=====================================================================================
// RTREngine.h
// Where the game code will reside, this class will load the renderer, and manage
// the different game objects. This class ensures the different components run and
// initialize in the correct order.
//=====================================================================================
#pragma once
#include <memory>

#include <RTR/Platform/Platform.h>
#include <RTR/Rendering/Renderer.h>
#include <RTR/Platform/AppBuilder.h>

#if RTR_PLATFORM == RTR_PLATFORM_WINDOWS
#include <Windows.h>
#endif

namespace RTR
{
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
			RTREngine(HINSTANCE &hInstance);
#endif

			//=====================================================================================
			// Member Variables
			//=====================================================================================
		private:
			std::unique_ptr<Platform::AppBuilder> app_;
			std::unique_ptr<Rendering::Renderer> renderer_;

			//=====================================================================================
			// Member Functions
			//=====================================================================================
		public:
			bool Initialize();
			void Shutdown();
			int Run();
			void Update(const float& deltaTime);
			void Render();
		};
	}
}