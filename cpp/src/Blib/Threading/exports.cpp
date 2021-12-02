#include <Blib/common.hpp>
#include <Blib/Manager.hpp>
#include <Blib/Threading/Job.hpp>
#include <Blib/Threading/Scheduler.hpp>
#include <chrono>

using namespace Jobs;

class SleepJob : public CJob
{
public:
	void Execute()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(mDuration));
	}

	long long mDuration = 0L;

protected:
	friend class CManager;

	static gmstring_t ObjectType;
};

gmstring_t SleepJob::ObjectType = "SleepJob";

GM_EXPORT gmreal_t blib_job_start(gmreal_t id)
{
	CScheduler::Instance().StartJob(BGetObject<CJob>(id));
	return GM_TRUE;
}

GM_EXPORT gmreal_t blib_job_is_finished(gmreal_t id)
{
	return BGetObject<CJob>(id)->IsFinished() ? GM_TRUE : GM_FALSE;
}

GM_EXPORT gmreal_t blib_get_finished_job()
{
	if (CJob* job = CScheduler::Instance().GetFinishedJob())
	{
		return job->GetId();
	}
	return ID_NONE;
}

GM_EXPORT gmreal_t blib_sleep_job_create(gmreal_t duration)
{
	SleepJob* sleepJob = BCreateObject<SleepJob>();
	sleepJob->mDuration = static_cast<long long>(duration);
	return sleepJob->GetId();
}
