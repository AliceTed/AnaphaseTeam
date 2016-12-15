#include "..\..\header\spawn\SpawnManager.h"
#include <algorithm>
#include <iterator>
SpawnManager::SpawnManager()
	:m_container(),
	m_current()
{
}

void SpawnManager::initialize()
{
	m_container.clear();
	m_current.clear();
}

void SpawnManager::add(const SpawnPoint & _point)
{
	m_container.emplace_back(_point);
}

void SpawnManager::update(float deltaTime)
{
	for (auto& i : m_current)
	{
		i.update(deltaTime);
	}
	remove();
}

void SpawnManager::draw(IRenderer * _renderer)
{
	for (auto& i : m_current)
	{
		i.draw(_renderer);
	}
}

void SpawnManager::createEnemy(EnemyManager & _enemyManager)
{
	move();
	for (auto& i : m_current)
	{
		i.initialize();
		i.createEnemy(_enemyManager);//.createEnemy(*this/*,EnemyFactory()*/);
	}
}

void SpawnManager::remove()
{
	auto itr = std::remove_if(m_current.begin(),m_current.end(), [](SpawnPoint& _point){return _point.isEnd();});
	m_current.erase(itr, m_current.end());
}

void SpawnManager::move()
{
	if (isEnd())return;
	auto min = std::min_element(m_container.begin(), m_container.end(), [](SpawnPoint& _x, SpawnPoint& _y) {return _x.getActiveNumber() < _y.getActiveNumber();});
	unsigned int number=min->getActiveNumber();
	for (auto& i:m_container)
	{
		if (i.getActiveNumber() == number)
		{
			m_current.emplace_back(i);
		}
	}

	auto itr = std::remove_if(m_container.begin(), m_container.end(), [number](SpawnPoint& _point) {return number == _point.getActiveNumber();});
	m_container.erase(itr, m_container.end());
}

const bool SpawnManager::isCurrentEnd() const
{
	return m_current.empty();
}

const bool SpawnManager::isEnd() const
{
	return isCurrentEnd()&&m_container.empty();
}
