#pragma once

#include "common.hpp"
#include "Object.hpp"
#include <mutex>
#include <queue>
#include <vector>

#define ID_REUSE_THRESHOLD 100000

class Manager
{
public:
	~Manager();

	/** Retrieves the singleton. */
	static Manager& Instance();

	/**
	 * Creates a new object.
	 */
	template<class T>
	T* Create()
	{
		T* object = new T();
		object->mType = T::mObjectType;

		{
			std::unique_lock<std::mutex> lock(mMutex);
			gmreal_t id;

			if (mIdAvailable.size() > ID_REUSE_THRESHOLD)
			{
				id = mIdAvailable.front();
				mIdAvailable.pop();
				mObjects[static_cast<size_t>(id)] = object;
			}
			else
			{
				id = mIdNext++;
				mObjects.push_back(object);
			}

			object->mId = id;
		}
		
		return object;
	}

	/**
	 * Returns true if object with given id exists.
	 */
	bool Exists(gmreal_t id) const;

	/**
	 * Gets an object by its id.
	 *
	 * @param id The id of the object.
	 *
	 * @return The object or nullptr on fail.
	 */
	template<class T>
	T* Get(gmreal_t id)
	{
		std::unique_lock<std::mutex> lock(mMutex);
		return static_cast<T*>(mObjects.at(static_cast<size_t>(id)));
	}

	/**
	 * Destroys an object.
	 *
	 * @param id The id of the object.
	 */
	void Destroy(gmreal_t id);

private:
	Manager() {}

	/** Used for locking structures when adding, getting, removing etc. objects. */
	std::mutex mMutex;

	/** The id of the next added object. */
	gmreal_t mIdNext = 0.0;

	/** Ids available for reuse. */
	std::queue<gmreal_t> mIdAvailable;

	/** List of all added objects. */
	std::vector<Object*> mObjects;
};

/**
 * Creates a new object of given type.
 *
 * @return The created object.
 */
template<class T>
inline T* BCreateObject()
{
	return Manager::Instance().Create<T>();
}

/** Returns true if object with given id exists. */
inline bool BExists(gmreal_t id)
{
	return Manager::Instance().Exists(id);
}

/**
 * Retrives an object by its id.
 *
 * @param id The id of the object.
 *
 * @return The object with specified id.
 */
template<class T>
inline T* BGetObject(gmreal_t id)
{
	return Manager::Instance().Get<T>(id);
}

/** Destroys the object. */
inline void BDestroy(gmreal_t id)
{
	Manager::Instance().Destroy(id);
}

/** Destroys the object. */
inline void BDestroy(Object* object)
{
	Manager::Instance().Destroy(object->GetId());
}
