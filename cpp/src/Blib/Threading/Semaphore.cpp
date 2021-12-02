#include <Blib/Threading/Semaphore.hpp>

using namespace Jobs;

CSemaphore::CSemaphore(unsigned count)
	: mCount(count)
{
}

CSemaphore::~CSemaphore()
{
}

void CSemaphore::Acquire()
{
	std::unique_lock<std::mutex> lock(Mutex);
	while (mCount == 0)
	{
		mCondVar.wait(lock);
	}
	--mCount;
}

void CSemaphore::Release()
{
	{
		std::unique_lock<std::mutex> lock(Mutex);
		++mCount;
	}
	mCondVar.notify_one();
}
