#include <RTR/Utilities/Timer.h>

using namespace std::chrono;

namespace RTR
{
	namespace Utilities
	{
		//=====================================================================================
		// Constructors, Destructors, Copy Constructors and Move Constructors
		//=====================================================================================
		Timer::Timer() :
			deltaTime_(-1.0),
			pausedTime_(0),
			isTimeStopped_(false),
			baseTime_(high_resolution_clock::now()),
			previousTime_(high_resolution_clock::now())
		{
		}

		//=====================================================================================
		// Member Functions
		//=====================================================================================
		float Timer::TotalTimeSeconds() const
		{
			microseconds elapsedTime;
			// If we are stopped, do not count the time that has passed since we stopped.
			// Moreover, if we previously already had a pause, the distance 
			// mStopTime - mBaseTime includes paused time, which we do not want to count.
			// To correct this, we can subtract the paused time from mStopTime:  
			if (isTimeStopped_)
			{
				elapsedTime = duration_cast<microseconds>((stopTime_ - pausedTime_) - baseTime_);
				return static_cast<float>(elapsedTime.count() / 1000000.0);
			}

			// The distance mCurrTime - mBaseTime includes paused time,
			// which we do not want to count.  To correct this, we can subtract 
			// the paused time from mCurrTime:  
			
			else
			{
				elapsedTime = duration_cast<microseconds>((currentTime_ - pausedTime_) - baseTime_);
				return static_cast<float>(elapsedTime.count() / 1000000.0);
			}
		}

		float Timer::DeltaTime() const
		{
			return static_cast<float>(deltaTime_);
		}
		void Timer::Reset()
		{
			baseTime_ = high_resolution_clock::now();
			previousTime_ = high_resolution_clock::now();
			isTimeStopped_ = false;
		}
		void Timer::Start()
		{
			high_resolution_clock::time_point startTime = high_resolution_clock::now();
			// Accumulate the time elapsed between stop and start pairs.

			if (isTimeStopped_)
			{
				pausedTime_ += startTime - stopTime_;
				previousTime_ = startTime;
				isTimeStopped_ = false;
			}
		}
		void Timer::Stop()
		{
			if (!isTimeStopped_)
			{
				stopTime_ = high_resolution_clock::now();
				isTimeStopped_ = true;
			}
		}
		void Timer::Tick()
		{
			if (isTimeStopped_)
			{
				deltaTime_ = 0.0;
				return;
			}

			currentTime_ = high_resolution_clock::now();
			microseconds time = duration_cast<microseconds>(currentTime_ - previousTime_);
			// Time difference between this frame and the previous.
			deltaTime_ = static_cast<double>((time.count() / 1000000.0));
			// Prepare for next frame.
			previousTime_ = currentTime_;

			if (deltaTime_ < 0.0)
			{
				deltaTime_ = 0.0;
			}
		}
	}
}