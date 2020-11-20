#include <Blib/Manager.hpp>

Manager::~Manager()
{
	for (Object* o : mObjects)
	{
		delete o;
	}
	mObjects.clear();
}

Manager& Manager::Instance()
{
	static Manager manager;
	return manager;
}

bool Manager::Exists(gmreal_t id) const
{
	size_t pos = static_cast<size_t>(id);
	if (id < 0.0 || pos >= mObjects.size())
	{
		return false;
	}
	return mObjects.at(pos) != nullptr;
}

void Manager::Destroy(gmreal_t id)
{
	std::unique_lock<std::mutex> lock(mMutex);
	size_t pos = static_cast<size_t>(id);
	delete mObjects.at(pos);
	mObjects[pos] = nullptr;
	mIdAvailable.push(id);
}
