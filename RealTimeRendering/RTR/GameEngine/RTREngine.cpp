//=====================================================================================
// RTREngine.h
// Where the game code will reside, this class will load the renderer, and manage
// the different game objects. This class ensures the different components run and
// initialize in the correct order.
//=====================================================================================

#include <RTR/GameEngine/RTREngine.h>
#include <sstream>

#if RTR_PLATFORM == RTR_PLATFORM_WINDOWS 
#include <RTR/Platform/Windows/WinBuilder.h>
#include <RTR/Rendering/DirectX/DirectXRenderer.h>
#endif
namespace RTR
{
	namespace GameEngine
	{
		//=====================================================================================
		// Constructors, Destructors, Copy Constructors and Move Constructors
		//=====================================================================================
#if RTR_PLATFORM == RTR_PLATFORM_WINDOWS
		//Custom Constructor for Windows Platform
		RTREngine::RTREngine(HINSTANCE &hInstance) :
			appTitle_(L"Real Time Rendering Project"),
			app_(std::make_unique<Platform::Windows::WinBuilder>(hInstance, L"Real Time Rendering Project")),
			renderer_(std::make_unique<Rendering::DirectX::DirectXRenderer>(hInstance))
		{
		}
#endif

		//=====================================================================================
		// Member Functions
		//=====================================================================================
		bool RTREngine::Initialize()
		{
			if (!app_->Initialize())
			{
				return false;
			}
			if (!renderer_->Initialize())
			{
				return false;
			}
			return true;
		}
		void RTREngine::Shutdown()
		{
			renderer_->Shutdown();
		}
		int RTREngine::Run()
		{
			return app_->Run(this);
		}
		void RTREngine::Update()
		{
			gameTimer_.Tick();
			const float deltaTime = gameTimer_.DeltaTime();
			//Where game objects get updated
		}

		void RTREngine::Render()
		{
			renderer_->BeginFrame();

			//Where game objects get drawn

			renderer_->EndFrame();
		}
		void RTREngine::CheckFrameStats()
		{
			const float deltaTime = gameTimer_.DeltaTime();

			static float timeElapsed = 0.0f;
			if ((gameTimer_.TotalTimeSeconds() - timeElapsed) >= 1.0f)
			{
				//Code To Test Timer
				std::wostringstream out;
				out << appTitle_ << L" ,   Delta Time (ms): " << 1000.0f * deltaTime << L"   Total Elapsed time: " << timeElapsed; //Shows time in milliseconds
				SetWindowText(GetActiveWindow(), out.str().c_str());

				timeElapsed += 1.0f;
			}
		}
	}
}