#pragma once

#include "common.hpp"

class Manager;

class Object
{
public:
	/** Returns the id of the object. */
	inline gmreal_t GetId() const
	{
		return mId;
	}

	/** Returns the type name of the object. */
	inline gmstring_t GetType() const
	{
		return mType;
	}

protected:
	friend class Manager;

	Object();

	virtual ~Object();

	/** The type name of the object. */
	static gmstring_t mObjectType;

	/** Copy of object's type name. */
	gmstring_t mType = nullptr;

	/** The id of the object. */
	gmreal_t mId = -1.0;
};