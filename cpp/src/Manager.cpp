#include "Manager.hpp"

Manager::~Manager()
{
	for (auto it = mObjects.begin(); it != mObjects.end(); ++it)
	{
		delete it->second;
	}
}

Manager& Manager::Instance()
{
	static Manager manager;
	return manager;
}

bool Manager::Destroy(gmreal_t id)
{
	std::unique_lock<std::mutex> lock(mMutex);
	auto it = mObjects.find(id);
	if (it != mObjects.end())
	{
		delete it->second;
		mObjects.erase(it);
		mIdAvailable.push(id);
		return true;
	}
	return false;
}