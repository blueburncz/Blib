#pragma once

#include "../common.hpp"
#include <mutex>
#include <condition_variable>

namespace Jobs
{
	class Semaphore final
	{
	public:
		Semaphore(unsigned count = 0);

		~Semaphore();

		void Acquire();

		void Release();

	private:
		std::mutex mMutex;

		std::condition_variable mCondVar;

		unsigned mCount;
	};
}