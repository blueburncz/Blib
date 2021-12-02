#include <Blib/Threading/Scheduler.hpp>
#include <Blib/Threading/Worker.hpp>
#include <Blib/Threading/Job.hpp>

using namespace Jobs;

CWorker::CWorker(CScheduler* scheduler)
	: Scheduler(scheduler)
	, Thread(std::thread(&CWorker::Work, this))
{
}

CWorker::~CWorker()
{
	Running = false;
	Thread.join();
}

void CWorker::Work()
{
	while (Running)
	{
		CJob* job = Scheduler->GetJob();
		job->Execute();
		Scheduler->AddFinishedJob(job);
	}
}
