//=====================================================================================
// DirectXRennderer.h
// Main Rendering class that initializes DirectX and manages frame buffers 
//=====================================================================================
#pragma once
#include <RTR/Rendering/Renderer.h>
#include <cstdint>

#include <RTR/Platform/Platform.h>
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
				DirectXRenderer(GameEngine::RTREngine* const engine);
				virtual ~DirectXRenderer() final override;
				//=====================================================================================
				// Member Variables
				//=====================================================================================
			private:
				HINSTANCE hInstance_;
				uint32_t screenWidth_;
				uint32_t screenHeight_;
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