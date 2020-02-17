#pragma once

#include "../common.hpp"

namespace Jobs
{
	class Manager;

	class Job
	{
	public:
		Job();

		virtual ~Job();

		/** Executes the job. Must be implemented in child classes! */
		virtual void Execute() = 0;

		/** Returns the ID of the job, which can be the used in GM. */
		double GetId() const
		{
			return mId;
		}

		/** Returns true if the jobs is finished. */
		bool IsFinished() const
		{
			return mFinished;
		}

	protected:
		friend class Manager;

		/** The id of the job. */
		double mId = -1.0;

		/** True if the job is finished. */
		bool mFinished = false;
	};
}