#include "Job.hpp"
#include "Manager.hpp"

using namespace Jobs;

Job::Job()
{
	Manager::Instance()->RegisterJob(this);
}

Job::~Job()
{
}