//=====================================================================================
// DirectXRennderer.h
// Main Rendering class that initializes DirectX and manages frame buffers 
//=====================================================================================
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
				//=====================================================================================
				// Constructors, Destructors, Copy Constructors and Move Constructors
				//=====================================================================================
			public:
				DirectXRenderer() = delete;
				DirectXRenderer(HINSTANCE& hInstance);
				virtual ~DirectXRenderer() final override;
				//=====================================================================================
				// Member Variables
				//=====================================================================================
			private:
				HINSTANCE &hInstance_;
				//=====================================================================================
				// Member Functions
				//=====================================================================================
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