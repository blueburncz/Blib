#include "Semaphore.hpp"

using namespace Jobs;

Semaphore::Semaphore(unsigned count)
	: mCount(count)
{
}

Semaphore::~Semaphore()
{
}

void Semaphore::Acquire()
{
	std::unique_lock<std::mutex> lock(mMutex);
	while (mCount == 0)
	{
		mCondVar.wait(lock);
	}
	--mCount;
}

void Semaphore::Release()
{
	{
		std::unique_lock<std::mutex> lock(mMutex);
		++mCount;
	}
	mCondVar.notify_one();
}