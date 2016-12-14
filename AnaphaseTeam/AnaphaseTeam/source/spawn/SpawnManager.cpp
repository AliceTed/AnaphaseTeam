#include "..\..\header\spawn\SpawnManager.h"
#include <algorithm>
SpawnManager::SpawnManager()
	:m_container()
{
}

void SpawnManager::add(const SpawnPoint & _point)
{
	m_container.emplace_back(_point);
}

void SpawnManager::update(float deltaTime)
{
	for (auto& i:m_container )
	{
		i.update(deltaTime);
	}
}

void SpawnManager::draw(IRenderer * _renderer)
{
	for (auto& i : m_container)
	{
		i.draw(_renderer);
	}
}

void SpawnManager::sort()
{
	std::sort(m_container.begin(), m_container.end(), [](SpawnPoint& _x,SpawnPoint& _y) {return _x.getActiveNumber() < _y.getActiveNumber();});
}

void SpawnManager::remove()
{
	auto itr = std::remove_if(m_container.begin(), m_container.end(), [](SpawnPoint& _point){return _point.isEnd();});
	m_container.erase(itr, m_container.end());
}
