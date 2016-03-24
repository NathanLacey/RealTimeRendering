//=====================================================================================
// Timer.h
// Timer class designed to check time differences, can be used for multiple
// Situations
//=====================================================================================

#pragma once

#include <chrono>

namespace RTR
{
	namespace Utilities
	{
		class Timer
		{
		public:
			Timer();
			~Timer() = default;

			float TotalTimeSeconds()const;  // in seconds
			float DeltaTime()const; // in seconds

			void Reset(); // Call before message loop.
			void Start(); // Call when unpaused.
			void Stop();  // Call when paused.
			void Tick();  // Call every frame.
		private:
			std::chrono::high_resolution_clock::time_point baseTime_;
			std::chrono::high_resolution_clock::time_point stopTime_;
			std::chrono::high_resolution_clock::time_point previousTime_;
			std::chrono::high_resolution_clock::time_point currentTime_;
			std::chrono::high_resolution_clock::duration pausedTime_;
			double deltaTime_;
			bool isTimeStopped_;

		};
	}
}