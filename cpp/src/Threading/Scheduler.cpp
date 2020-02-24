#include "Scheduler.hpp"

using namespace Jobs;

Scheduler::Scheduler()
{
	unsigned workers = std::thread::hardware_concurrency();
	
	if (workers == 0)
	{
		workers = 1;
	}

	for (unsigned i = 0; i < workers; ++i)
	{
		mWorkers.push_back(new Worker(this));
	}
}

Scheduler::~Scheduler()
{
	for (auto worker : mWorkers)
	{
		delete worker;
	}
	mWorkers.clear();

	for (Job* j : mJobsWaiting)
	{
		delete j;
	}
	mJobsWaiting.clear();

	while (!mJobsFinished.empty())
	{
		Job* job = mJobsFinished.front();
		mJobsFinished.pop();
		delete job;
	}
}

Scheduler& Scheduler::Instance()
{
	static Scheduler scheduler;
	return scheduler;
}

void Scheduler::StartJob(Job* job)
{
	{
		std::unique_lock<std::mutex> lock(mMutex);
		mJobsWaiting.push_back(job);
	}
	mSemaphore.Release();
}

Job* Scheduler::GetJob()
{
	mSemaphore.Acquire();
	std::unique_lock<std::mutex> lock(mMutex);
	Job* job = mJobsWaiting.front();
	mJobsWaiting.erase(mJobsWaiting.begin());
	return job;
}

bool Scheduler::RemoveJob(Job* job)
{
	std::unique_lock<std::mutex> lock(mMutex);
	auto end = mJobsWaiting.end();
	auto it = std::find(mJobsWaiting.begin(), end, job);
	if (it == end)
	{
		return false;
	}
	mJobsWaiting.erase(it);
	mSemaphore.Acquire();
	return true;
}

void Scheduler::AddFinishedJob(Job* job)
{
	std::unique_lock<std::mutex> lock(mMutex);
	job->mFinished = true;
	mJobsFinished.push(job);
}

Job* Scheduler::GetFinishedJob()
{
	std::unique_lock<std::mutex> lock(mMutex);
	Job* job = nullptr;
	if (!mJobsFinished.empty())
	{
		job = mJobsFinished.front();
		mJobsFinished.pop();
	}
	return job;
}