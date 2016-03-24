#pragma once
#include <RTR/Platform/Platform.h>
#include <RTR/Rendering/Renderer.h>

#if RTR_PLATFORM == RTR_PLATFORM_WINDOWS
#include <Windows.h>
#include <d3d11_2.h>

namespace RTR
{
	namespace Rendering
	{
		namespace DirectX
		{
			class DirectXRenderer : public Renderer
			{
			public:
				DirectXRenderer() = delete;
				DirectXRenderer(HINSTANCE& hInstance);
				virtual ~DirectXRenderer() final override;

			private:
				HINSTANCE &hInstance_;

			public:
				virtual bool Initialize() final override;
				virtual void Shutdown() final override;
				virtual void OnResize() final override;
				virtual void BeginFrame() final override;
				virtual void EndFrame() final override;
			};
		}
	}
}
#endif