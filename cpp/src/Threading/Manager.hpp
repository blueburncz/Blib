#pragma once

#include "../common.hpp"
#include "Job.hpp"
#include "Semaphore.hpp"
#include "Worker.hpp"
#include <map>
#include <mutex>
#include <shared_mutex>
#include <queue>
#include <thread>
#include <vector>

namespace Jobs
{
	class Manager final
	{
	public:
		static Manager* Instance();
		~Manager();

		/** Registers a job. All jobs must call this method upon their creation! */
		void RegisterJob(Job* job);

		/** Gets a job by its id. */
		Job* GetJobById(double id);

		/** Adds job to the queue of jobs awaiting for execution. */
		void StartJob(double job);

		/** Gets a job for a worker. Blocks until there is some available. */
		Job* GetJob();

		/** Adds finished job. */
		void AddFinishedJob(Job* job);

		/** Returns nullptr if there are no finished jobs. */
		Job* GetFinishedJob();

		/** Destroys the job. */
		void DestroyJob(double id);

	private:
		Manager();

		/** Manager singleton. */
		static Manager* mInstance;

		/** The ID of the next job. */
		double mNextId = 0.0;

		/** Map of all existing jobs. */
		std::map<double, Job*> mJobs;

		/** Jobs to be executed. */
		std::queue<Job*> mJobsWaiting;

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