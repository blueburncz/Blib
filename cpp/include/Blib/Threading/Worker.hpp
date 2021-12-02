#pragma once

#include "../common.hpp"
#include <thread>

namespace Jobs
{
	class CWorker final
	{
	public:
		CWorker(class CScheduler* scheduler);

		~CWorker();

	private:
		void Work();

		class CScheduler* Scheduler;

		std::thread Thread;

		bool Running = true;
	};
}
