#include <Blib/Manager.hpp>

CManager::~CManager()
{
	for (CObject* o : Objects)
	{
		delete o;
	}
	Objects.clear();
}

CManager& CManager::Instance()
{
	static CManager manager;
	return manager;
}

bool CManager::Exists(gmreal_t id) const
{
	size_t pos = static_cast<size_t>(id);
	if (id < 0.0 || pos >= Objects.size())
	{
		return false;
	}
	return Objects.at(pos) != nullptr;
}

void CManager::Destroy(gmreal_t id)
{
	std::unique_lock<std::mutex> lock(Mutex);
	size_t pos = static_cast<size_t>(id);
	delete Objects.at(pos);
	Objects[pos] = nullptr;
	IdAvailable.push(id);
}
