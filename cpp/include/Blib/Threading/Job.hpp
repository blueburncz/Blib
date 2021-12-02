#pragma once

#include "../common.hpp"
#include "../Object.hpp"

namespace Jobs
{
	class CJob : public CObject
	{
	public:
		/** Executes the job. Must be implemented in child classes! */
		virtual void Execute() = 0;

		/** Returns true if the jobs is finished. */
		bool IsFinished() const
		{
			return Finished;
		}

	protected:
		friend class CManager;

		friend class CScheduler;

		CJob();

		virtual ~CJob();

		static gmstring_t ObjectType;

		/** True if the job is finished. */
		bool Finished = false;
	};
}
