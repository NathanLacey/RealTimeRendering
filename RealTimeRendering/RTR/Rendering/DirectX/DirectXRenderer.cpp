//=====================================================================================
// DirectXRender.cpp
// Main Rendering class that initializes DirectX and manages frame buffers 
//=====================================================================================
#include <RTR/Rendering/DirectX/DirectXRenderer.h>
#include <RTR/GameEngine/RTREngine.h>

#if RTR_PLATFORM == RTR_PLATFORM_WINDOWS
namespace RTR
{
	namespace Rendering
	{
		namespace DirectX
		{
			//=====================================================================================
			// Constructors, Destructors, Copy Constructors and Move Constructors
			//=====================================================================================
			DirectXRenderer::DirectXRenderer(GameEngine::RTREngine* const engine) :
				Renderer(engine),
				hInstance_(nullptr)
			{
			}

			DirectXRenderer::~DirectXRenderer()
			{
			}

			//=====================================================================================
			// Member Functions
			//=====================================================================================
			bool DirectXRenderer::Initialize()
			{
				hInstance_ = engine_->GetInstance();
				screenWidth_ = engine_->GetScreenWidth();
				screenHeight_ = engine_->GetScreenHeight();
				return true;
			}

			void DirectXRenderer::Shutdown()
			{
			}

			void DirectXRenderer::OnResize()
			{
			}

			void DirectXRenderer::BeginFrame()
			{
			}
			void DirectXRenderer::EndFrame()
			{
			}

		}
	}
}
#endif