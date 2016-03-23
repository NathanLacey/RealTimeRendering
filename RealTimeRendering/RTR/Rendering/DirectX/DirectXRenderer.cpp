#include "DirectXRenderer.h"

namespace RTR
{
	namespace Rendering
	{
		namespace DirectX
		{
			DirectXRenderer::DirectXRenderer(HINSTANCE & hInstance) :
				hInstance_(hInstance)
			{
			}

			DirectXRenderer::~DirectXRenderer()
			{
			}

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
