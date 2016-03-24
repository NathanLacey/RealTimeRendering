//=====================================================================================
// DirectXRender.cpp
// Main Rendering class that initializes DirectX and manages frame buffers 
//=====================================================================================
#include <RTR/Rendering/DirectX/DirectXRenderer.h>

namespace RTR
{
	namespace Rendering
	{
		namespace DirectX
		{
			//=====================================================================================
			// Constructors, Destructors, Copy Constructors and Move Constructors
			//=====================================================================================
			DirectXRenderer::DirectXRenderer(HINSTANCE & hInstance) :
				hInstance_(hInstance)
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
