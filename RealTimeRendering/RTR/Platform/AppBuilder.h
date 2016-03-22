//=====================================================================================
// AppBase.h
// Abstract Base Class, used to enable platform Independence
//=====================================================================================
#pragma once
#include <RTR/Platform/Platform.h>
namespace RTR
{
	namespace Platform
	{
		class AppBuilder
		{
		public:
			AppBuilder() = default;
			virtual ~AppBuilder() {}
			virtual bool AdjustSizeAndCreateWindow() = 0;
			virtual bool Initialize() = 0;
			virtual int Run() = 0;
		};
	}
}