#include <RTR/GameEngine/RTREngine.h>

namespace RTR
{
	namespace GameEngine
	{
#if RTR_PLATFORM == RTR_PLATFORM_WINDOWS
		RTREngine::RTREngine(HINSTANCE &hInstance)
		{
			app_ = std::make_unique<RTR::Platform::Windows::WinBuilder>(hInstance);
		}
#endif
		bool RTREngine::Initialize()
		{
			return app_->Initialize();
		}
		void RTREngine::Shutdown()
		{
		}
		int RTREngine::Run()
		{
			return app_->Run();
		}
	}
}