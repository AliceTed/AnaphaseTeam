#include "../../../header/actor/Enemy/EnemyManager.h"
#include <algorithm>
EnemyManager::EnemyManager()
	:m_enemys()
{
}

void EnemyManager::initialize()
{
	m_enemys.clear();
}

void EnemyManager::add(Enemy * _enemy)
{
	m_enemys.emplace_back( _enemy);
	m_enemys.back()->initialize();
}

void EnemyManager::update(float deltaTime)
{
	for (auto& i : m_enemys) { i->update(deltaTime); }
	remove();
}

void EnemyManager::collisionGround(const Map & _map)
{
	for (auto& i : m_enemys) { i->collisionGround(_map); }
}

void EnemyManager::draw(const Renderer & _renderer, const Camera& _camera)
{
	for (auto& i : m_enemys) { i->draw(_renderer,_camera); }
}

void EnemyManager::remove()
{
	auto itr = std::remove_if(m_enemys.begin(), m_enemys.end(), [](Enemy_Ptr& _e) {return _e->isDead();});
	m_enemys.erase(itr,m_enemys.end());
}
