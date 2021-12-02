#pragma once

#include "common.hpp"
#include "Object.hpp"
#include <mutex>
#include <queue>
#include <vector>

#define ID_REUSE_THRESHOLD 100000

class CManager
{
public:
	~CManager();

	/** Retrieves the singleton. */
	static CManager& Instance();

	/**
	 * Creates a new object.
	 */
	template<class T>
	T* Create()
	{
		T* object = new T();
		object->Type = T::ObjectType;

		{
			std::unique_lock<std::mutex> lock(Mutex);
			gmreal_t id;

			if (IdAvailable.size() > ID_REUSE_THRESHOLD)
			{
				id = IdAvailable.front();
				IdAvailable.pop();
				Objects[static_cast<size_t>(id)] = object;
			}
			else
			{
				id = IdNext++;
				Objects.push_back(object);
			}

			object->Id = id;
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
		std::unique_lock<std::mutex> lock(Mutex);
		return static_cast<T*>(Objects.at(static_cast<size_t>(id)));
	}

	/**
	 * Destroys an object.
	 *
	 * @param id The id of the object.
	 */
	void Destroy(gmreal_t id);

private:
	CManager() {}

	/** Used for locking structures when adding, getting, removing etc. objects. */
	std::mutex Mutex;

	/** The id of the next added object. */
	gmreal_t IdNext = 0.0;

	/** Ids available for reuse. */
	std::queue<gmreal_t> IdAvailable;

	/** List of all added objects. */
	std::vector<CObject*> Objects;
};

/**
 * Creates a new object of given type.
 *
 * @return The created object.
 */
template<class T>
inline T* BCreateObject()
{
	return CManager::Instance().Create<T>();
}

/** Returns true if object with given id exists. */
inline bool BExists(gmreal_t id)
{
	return CManager::Instance().Exists(id);
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
	return CManager::Instance().Get<T>(id);
}

/** Destroys the object. */
inline void BDestroy(gmreal_t id)
{
	CManager::Instance().Destroy(id);
}

/** Destroys the object. */
inline void BDestroy(CObject* object)
{
	CManager::Instance().Destroy(object->GetId());
}
