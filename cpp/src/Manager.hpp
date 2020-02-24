#pragma once

#include "common.hpp"
#include "Object.hpp"
#include <map>
#include <mutex>
#include <queue>

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
		gmreal_t id;
		{
			std::unique_lock<std::mutex> lock(mMutex);
			if (mIdAvailable.size() > ID_REUSE_THRESHOLD)
			{
				id = mIdAvailable.front();
				mIdAvailable.pop();
			}
			else
			{
				id = mIdNext++;
			}
		}
		T* object = new T();
		object->mType = T::mObjectType;
		object->mId = id;
		{
			std::unique_lock<std::mutex> lock(mMutex);
			mObjects[id] = object;
		}
		return object;
	}

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
		if (mObjects.find(id) != mObjects.end())
		{
			return static_cast<T*>(mObjects.at(id));
		}
		return nullptr;
	}

	/**
	 * Destroys an object.
	 *
	 * @param id The id of the object.
	 *
	 * @return True on success.
	 */
	bool Destroy(gmreal_t id);

private:
	Manager() {}

	/** Used for locking structures when adding, getting, removing etc. objects. */
	std::mutex mMutex;

	/** The id of the next added object. */
	gmreal_t mIdNext = 0.0;

	/** Ids available for reuse. */
	std::queue<gmreal_t> mIdAvailable;

	/** Map of all added objects. */
	std::map<gmreal_t, Object*> mObjects;
};

/**
 * Creates a new object of given type.
 *
 * @return The created object.
 */
template<class T>
inline T* CreateObject()
{
	return Manager::Instance().Create<T>();
}

/**
 * Retrives an object by its id.
 *
 * @param id The id of the object.
 *
 * @return The object with specified id.
 */
template<class T>
inline T* GetObject(gmreal_t id)
{
	return Manager::Instance().Get<T>(id);
}

/** Destroys the object. */
inline bool Destroy(gmreal_t id)
{
	return Manager::Instance().Destroy(id);
}

/** Destroys the object. */
inline bool Destroy(Object* object)
{
	return Manager::Instance().Destroy(object->GetId());
}