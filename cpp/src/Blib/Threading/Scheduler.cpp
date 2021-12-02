#include <Blib/Threading/Scheduler.hpp>
#include <Blib/Threading/Job.hpp>
#include <Blib/Threading/Worker.hpp>

using namespace Jobs;

CScheduler::CScheduler()
{
	unsigned workers = std::thread::hardware_concurrency();
	
	if (workers == 0)
	{
		workers = 1;
	}

	for (unsigned i = 0; i < workers; ++i)
	{
		Workers.push_back(new CWorker(this));
	}
}

CScheduler::~CScheduler()
{
	for (auto worker : Workers)
	{
		delete worker;
	}
	Workers.clear();

	for (CJob* j : JobsWaiting)
	{
		delete j;
	}
	JobsWaiting.clear();

	while (!JobsFinished.empty())
	{
		CJob* job = JobsFinished.front();
		JobsFinished.pop();
		delete job;
	}
}

CScheduler& CScheduler::Instance()
{
	static CScheduler scheduler;
	return scheduler;
}

void CScheduler::StartJob(CJob* job)
{
	{
		std::unique_lock<std::mutex> lock(Mutex);
		JobsWaiting.push_back(job);
	}
	Semaphore.Release();
}

CJob* CScheduler::GetJob()
{
	Semaphore.Acquire();
	std::unique_lock<std::mutex> lock(Mutex);
	CJob* job = JobsWaiting.front();
	JobsWaiting.erase(JobsWaiting.begin());
	return job;
}

bool CScheduler::RemoveJob(CJob* job)
{
	std::unique_lock<std::mutex> lock(Mutex);
	auto end = JobsWaiting.end();
	auto it = std::find(JobsWaiting.begin(), end, job);
	if (it == end)
	{
		return false;
	}
	JobsWaiting.erase(it);
	Semaphore.Acquire();
	return true;
}

void CScheduler::AddFinishedJob(CJob* job)
{
	std::unique_lock<std::mutex> lock(Mutex);
	job->Finished = true;
	JobsFinished.push(job);
}

CJob* CScheduler::GetFinishedJob()
{
	std::unique_lock<std::mutex> lock(Mutex);
	CJob* job = nullptr;
	if (!JobsFinished.empty())
	{
		job = JobsFinished.front();
		JobsFinished.pop();
	}
	return job;
}
