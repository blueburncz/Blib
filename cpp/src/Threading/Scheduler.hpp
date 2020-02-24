#pragma once

#include "../common.hpp"
#include "Job.hpp"
#include "Semaphore.hpp"
#include "Worker.hpp"
#include <map>
#include <mutex>
#include <queue>
#include <shared_mutex>
#include <thread>
#include <vector>

namespace Jobs
{
	class Scheduler final
	{
	public:
		static Scheduler& Instance();

		~Scheduler();

		/** Adds job to the queue of jobs awaiting for execution. */
		void StartJob(Job* job);

		/** Gets a job for a worker. Blocks until there is some available. */
		Job* GetJob();

		/** Removes job from queue. */
		bool RemoveJob(Job* job);

		/** Adds finished job. */
		void AddFinishedJob(Job* job);

		/** Returns nullptr if there are no finished jobs. */
		Job* GetFinishedJob();

	private:
		Scheduler();

		/** Jobs to be executed. */
		std::vector<Job*> mJobsWaiting;

		/** Finished jobs. */
		std::queue<Job*> mJobsFinished;

		/** Workers executing the jobs. */
		std::vector<Worker*> mWorkers;

		/** Mutex used for locking shared data structures. */
		std::mutex mMutex;

		/** Semaphore used for notifying workers about new jobs. */
		Semaphore mSemaphore;
	};
}