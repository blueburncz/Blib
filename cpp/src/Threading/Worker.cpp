#include "Manager.hpp"
#include "Worker.hpp"

using namespace Jobs;

Worker::Worker(Manager* manager)
	: mManager(manager)
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
		Job* job = mManager->GetJob();
		job->Execute();
		mManager->AddFinishedJob(job);
	}
}