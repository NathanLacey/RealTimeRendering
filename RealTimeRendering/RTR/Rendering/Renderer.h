//=====================================================================================
// Renderer.h
// Abstract Renderer class. As we begin the project, we will only be using DirectX
// But building a abract class underneath allows for more platform independence
// if we desire to incorporate OpenGL later on.
//=====================================================================================
#pragma once

namespace RTR
{
	namespace Rendering
	{
		class Renderer
		{
		public:
			Renderer() = default;
			virtual ~Renderer() {}
			
			virtual bool Initialize() = 0;
			virtual void Shutdown() = 0;
			virtual void OnResize() = 0;
			virtual void Render() = 0;
		};
	}
}