#pragma once

#include "../common.hpp"
#include <thread>

namespace Jobs
{
	class Manager;

	class Worker final
	{
	public:
		Worker(Manager* manager);

		~Worker();

	private:
		void Work();

		Manager* mManager;

		std::thread mThread;

		bool mRunning = true;
	};
}