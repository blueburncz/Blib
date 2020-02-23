#include "../common.hpp"
#include "../Manager.hpp"
#include "Job.hpp"
#include "Scheduler.hpp"
#include <chrono>

using namespace Jobs;

class SleepJob : public Job
{
public:
	void Execute()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(mDuration));
	}

	long long mDuration = 0L;

protected:
	friend class Manager;

	static gmstring_t mObjectType;
};

gmstring_t SleepJob::mObjectType = "SleepJob";

GM_EXPORT gmreal_t b_job_start(gmreal_t id)
{
	Scheduler::Instance().StartJob(GetObject<Job>(id));
	return GM_TRUE;
}

GM_EXPORT gmreal_t b_job_is_finished(gmreal_t id)
{
	return GetObject<Job>(id)->IsFinished()
		? GM_TRUE
		: GM_FALSE;
}

GM_EXPORT gmreal_t b_get_finished_job()
{
	if (Job* job = Scheduler::Instance().GetFinishedJob())
	{
		return job->GetId();
	}
	return -1.0;
}

GM_EXPORT gmreal_t b_job_destroy(gmreal_t id)
{
	return Destroy(id)
		? GM_TRUE
		: GM_FALSE;
}

GM_EXPORT gmreal_t b_sleep_job_create(gmreal_t duration)
{
	SleepJob* sleepJob = CreateObject<SleepJob>();
	sleepJob->mDuration = (long long)duration;
	return sleepJob->GetId();
}