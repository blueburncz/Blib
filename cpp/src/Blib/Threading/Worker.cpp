#include <Blib/Threading/Scheduler.hpp>
#include <Blib/Threading/Worker.hpp>

using namespace Jobs;

Worker::Worker(Scheduler* scheduler)
	: mScheduler(scheduler)
	, mThread(std::thread(&Worker::Work, this))
{
}

Worker::~Worker()
{
	mRunning = false;
	mThread.join();
}

void Worker::Work()
{
	while (mRunning)
	{
		Job* job = mScheduler->GetJob();
		job->Execute();
		mScheduler->AddFinishedJob(job);
	}
}
