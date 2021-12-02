#pragma once

#include "../common.hpp"
#include "Semaphore.hpp"
#include <map>
#include <mutex>
#include <queue>
#include <shared_mutex>
#include <thread>
#include <vector>

namespace Jobs
{
	class CScheduler final
	{
	public:
		static CScheduler& Instance();

		~CScheduler();

		/** Adds job to the queue of jobs awaiting for execution. */
		void StartJob(class CJob* job);

		/** Gets a job for a worker. Blocks until there is some available. */
		class CJob* GetJob();

		/** Removes job from queue. */
		bool RemoveJob(class CJob* job);

		/** Adds finished job. */
		void AddFinishedJob(class CJob* job);

		/** Returns nullptr if there are no finished jobs. */
		class CJob* GetFinishedJob();

	private:
		CScheduler();

		/** Jobs to be executed. */
		std::vector<class CJob*> JobsWaiting;

		/** Finished jobs. */
		std::queue<class CJob*> JobsFinished;

		/** Workers executing the jobs. */
		std::vector<class CWorker*> Workers;

		/** Mutex used for locking shared data structures. */
		std::mutex Mutex;

		/** Semaphore used for notifying workers about new jobs. */
		CSemaphore Semaphore;
	};
}
