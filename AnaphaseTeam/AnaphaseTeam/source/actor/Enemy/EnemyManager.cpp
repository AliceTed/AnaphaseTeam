#include "../../../header/actor/Enemy/EnemyManager.h"
#include "../../../header/actor/Player/Player.h"
#include <algorithm>
#include "..\..\..\header\actor\Enemy\EnemyManager.h"
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
	m_enemys.emplace_back(Enemy_Ptr(_enemy));
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

void EnemyManager::collision(Actor & _actor)
{
	for (auto& i : m_enemys) { i->collision(_actor); }
}

void EnemyManager::draw(const Renderer & _renderer)
{
	for (auto& i : m_enemys) { i->draw(_renderer); }
	//_renderer.getDraw2D().string(std::to_string(size()).c_str(), &GSvector2(200,300),50);
}

Enemy_Ptr& EnemyManager::nearEnemy(Player * _player)
{
	std::sort(m_enemys.begin(), m_enemys.end(), [_player](Enemy_Ptr& _x, Enemy_Ptr& _y){return _x->distanceActor(*_player) < _y->distanceActor(*_player);});
	return *m_enemys.begin();
}

void EnemyManager::thinks(Player * _player)
{
	for (auto& i : m_enemys) { i->think(_player); }
}

int EnemyManager::size()
{
	return m_enemys.size();
}

void EnemyManager::remove()
{
	auto itr = std::remove_if(m_enemys.begin(), m_enemys.end(), [](Enemy_Ptr& _e) {return _e->isDead();});
	m_enemys.erase(itr,m_enemys.end());























}
