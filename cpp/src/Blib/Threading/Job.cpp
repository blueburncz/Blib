#include <Blib/Threading/Job.hpp>
#include <Blib/Threading/Scheduler.hpp>

using namespace Jobs;

gmstring_t CJob::ObjectType = "Job";

CJob::CJob()
{
}

CJob::~CJob()
{
	CScheduler::Instance().RemoveJob(this);
}
