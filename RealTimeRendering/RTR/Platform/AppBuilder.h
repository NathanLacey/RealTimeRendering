//=====================================================================================
// AppBase.h
// Abstract Base Class, used to enable platform Independence
//=====================================================================================
#pragma once

namespace RTR
{
	namespace GameEngine
	{
		//Forward declaration of RTREngine
		class RTREngine;
	}
	namespace Platform
	{
		class AppBuilder
		{
		public:
			AppBuilder() = default;
			virtual ~AppBuilder() = default;
			virtual bool AdjustSizeAndCreateWindow() = 0;
			virtual bool Initialize() = 0;
			virtual int Run(GameEngine::RTREngine* const) = 0;
		};
	}
}