#include "../common.hpp"
#include "Job.hpp"
#include "Manager.hpp"

using namespace Jobs;

GM_EXPORT double b_job_start(double id)
{
	Manager::Instance()->StartJob(id);
	return GM_TRUE;
}

GM_EXPORT double b_job_is_finished(double id)
{
	return Manager::Instance()->GetJobById(id)->IsFinished()
		? GM_TRUE
		: GM_FALSE;
}

GM_EXPORT double b_get_finished_job()
{
	if (Job* job = Manager::Instance()->GetFinishedJob())
	{
		return job->GetId();
	}
	return -1.0;
}

GM_EXPORT double b_job_destroy(double id)
{
	Manager::Instance()->DestroyJob(id);
	return GM_TRUE;
}