#include <Blib/common.hpp>
#include <Blib/Manager.hpp>
#include <Blib/Threading/Job.hpp>
#include <Blib/Threading/Scheduler.hpp>
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
	Scheduler::Instance().StartJob(BGetObject<Job>(id));
	return GM_TRUE;
}

GM_EXPORT gmreal_t b_job_is_finished(gmreal_t id)
{
	return BGetObject<Job>(id)->IsFinished() ? GM_TRUE : GM_FALSE;
}

GM_EXPORT gmreal_t b_get_finished_job()
{
	if (Job* job = Scheduler::Instance().GetFinishedJob())
	{
		return job->GetId();
	}
	return ID_NONE;
}

GM_EXPORT gmreal_t b_sleep_job_create(gmreal_t duration)
{
	SleepJob* sleepJob = BCreateObject<SleepJob>();
	sleepJob->mDuration = static_cast<long long>(duration);
	return sleepJob->GetId();
}
