#include <Blib/Threading/Job.hpp>
#include <Blib/Threading/Scheduler.hpp>

using namespace Jobs;

gmstring_t Job::mObjectType = "Job";

Job::Job()
{
}

Job::~Job()
{
	Scheduler::Instance().RemoveJob(this);
}
