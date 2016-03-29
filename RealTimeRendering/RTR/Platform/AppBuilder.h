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
			AppBuilder() = delete;
			AppBuilder(GameEngine::RTREngine* const engine) : engine_(engine) {};
			virtual ~AppBuilder() = default;
			virtual bool Initialize() = 0;
			virtual int Run() = 0;
		protected:
			GameEngine::RTREngine* engine_;
		};
	}
}