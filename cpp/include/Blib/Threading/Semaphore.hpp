#pragma once

#include "../common.hpp"
#include <condition_variable>
#include <mutex>

namespace Jobs
{
	class CSemaphore final
	{
	public:
		CSemaphore(unsigned count = 0);

		~CSemaphore();

		void Acquire();

		void Release();

	private:
		std::mutex Mutex;

		std::condition_variable mCondVar;

		unsigned mCount;
	};
}
