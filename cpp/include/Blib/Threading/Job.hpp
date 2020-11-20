#pragma once

#include "../common.hpp"
#include "../Object.hpp"

namespace Jobs
{
	class Scheduler;

	class Job : public Object
	{
	public:
		/** Executes the job. Must be implemented in child classes! */
		virtual void Execute() = 0;

		/** Returns true if the jobs is finished. */
		bool IsFinished() const
		{
			return mFinished;
		}

	protected:
		friend class Manager;

		friend class Scheduler;

		Job();

		virtual ~Job();

		static gmstring_t mObjectType;

		/** True if the job is finished. */
		bool mFinished = false;
	};
}
