#pragma once

#include "../common.hpp"
#include <thread>

namespace Jobs
{
	class Scheduler;

	class Worker final
	{
	public:
		Worker(Scheduler* scheduler);

		~Worker();

	private:
		void Work();

		Scheduler* mScheduler;

		std::thread mThread;

		bool mRunning = true;
	};
}
