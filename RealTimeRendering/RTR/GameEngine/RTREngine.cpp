#include <RTR/GameEngine/RTREngine.h>
#if RTR_PLATFORM == RTR_PLATFORM_WINDOWS 
#include <RTR/Platform/Windows/WinBuilder.h>
#include <RTR/Rendering/DirectX/DirectXRenderer.h>
#endif
namespace RTR
{
	namespace GameEngine
	{
#if RTR_PLATFORM == RTR_PLATFORM_WINDOWS
		RTREngine::RTREngine(HINSTANCE &hInstance) :
			app_(std::make_unique<Platform::Windows::WinBuilder>(hInstance)),
			renderer_(std::make_unique<Rendering::DirectX::DirectXRenderer>(hInstance))
		{
		}
#endif
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
		void RTREngine::Update(const float & deltaTime)
		{
			//Where game objects get updated
		}

		void RTREngine::Render()
		{
			renderer_->BeginFrame();

			//Where game objects get drawn

			renderer_->EndFrame();
		}
	}
}