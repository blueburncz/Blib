#pragma once

#include "common.hpp"

class CObject
{
public:
	/** Returns the id of the object. */
	inline gmreal_t GetId() const
	{
		return Id;
	}

	/** Returns the type name of the object. */
	inline gmstring_t GetType() const
	{
		return Type;
	}

protected:
	friend class CManager;

	CObject();

	virtual ~CObject();

	/** The type name of the object. */
	static gmstring_t ObjectType;

	/** Copy of object's type name. */
	gmstring_t Type = nullptr;

	/** The id of the object. */
	gmreal_t Id = -1.0;
};
