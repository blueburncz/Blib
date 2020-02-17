#include "Manager.hpp"

using namespace Jobs;

Manager* Manager::mInstance = nullptr;

Manager::Manager()
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

Manager::~Manager()
{
	for (auto worker : mWorkers)
	{
		delete worker;
	}
	mWorkers.clear();

	mJobs.clear();

	while (!mJobsWaiting.empty())
	{
		Job* job = mJobsWaiting.front();
		mJobsWaiting.pop();
		delete job;
	}

	while (!mJobsFinished.empty())
	{
		Job* job = mJobsFinished.front();
		mJobsFinished.pop();
		delete job;
	}
}

Manager* Manager::Instance()
{
	if (!mInstance)
	{
		mInstance = new Manager();
	}
	return mInstance;
}

void Manager::RegisterJob(Job* job)
{
	std::unique_lock<std::mutex> lock(mMutex);
	double id = mNextId++;
	job->mId = id;
	mJobs[id] = job;
}

Job* Manager::GetJobById(double id)
{
	std::unique_lock<std::mutex> lock(mMutex);
	return mJobs[id];
}

void Manager::StartJob(double id)
{
	{
		std::unique_lock<std::mutex> lock(mMutex);
		mJobsWaiting.push(mJobs[id]);
	}
	mSemaphore.Release();
}

Job* Manager::GetJob()
{
	mSemaphore.Acquire();
	std::unique_lock<std::mutex> lock(mMutex);
	Job* job = mJobsWaiting.front();
	mJobsWaiting.pop();
	return job;
}

void Manager::AddFinishedJob(Job* job)
{
	std::unique_lock<std::mutex> lock(mMutex);
	job->mFinished = true;
	mJobsFinished.push(job);
}

Job* Manager::GetFinishedJob()
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

void Manager::DestroyJob(double id)
{
	auto it = mJobs.find(id);
	if (it != mJobs.end())
	{
		delete it->second;
		mJobs.erase(it);
	}
}