#include "../../../header/actor/Enemy/EnemyManager.h"
#include "../../../header/actor/Player/Player.h"
#include <algorithm>
#include "../../../header/camera/LockOn.h"
#include "../../../header/actor/Enemy/Enemy.h"
#include "../../../header/map/Map.h"
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

void EnemyManager::add(Enemy_Ptr _enemy)
{
	m_enemys.emplace_back(_enemy);
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

void EnemyManager::draw(IRenderer * _renderer)
{
	for (auto& i : m_enemys) { i->draw(_renderer); }
}

std::weak_ptr<Enemy> EnemyManager::nearEnemy(Player * _player)
{
	std::sort(m_enemys.begin(), m_enemys.end(), [_player](Enemy_Ptr& _x, Enemy_Ptr& _y){return _x->distanceActor(*_player) < _y->distanceActor(*_player);});
	if (m_enemys.empty())
	{
		return std::weak_ptr<Enemy>();
	}
	return *m_enemys.begin();
}

void EnemyManager::thinks(Player * _player)
{
	for (auto& i : m_enemys) { i->think(_player); }
}

const unsigned int EnemyManager::size()const
{
	return m_enemys.size();
}

void EnemyManager::remove()
{
	auto itr = std::remove_if(m_enemys.begin(), m_enemys.end(), [](Enemy_Ptr& _e) {return _e->isDead(); });
	m_enemys.erase(itr, m_enemys.end());
}

float EnemyManager::requestDistancePlayer(Enemy * _enemy)
{
	return _enemy->distanceActor(*m_player);
}

bool EnemyManager::requestDistanceOtherEnemy(Enemy * _enemy)
{
	return false;
}

bool EnemyManager::reqestGoToNear()
{
	//NEAR‚Ì‚â‚Â‚ª‚¢‚é‚©ŒŸõ
	auto itr = std::find_if(m_enemys.begin(), m_enemys.end(), [](Enemy_Ptr& _e) {return _e->currentDistance() == EAI::ATTACKRANGE; });
	//‹‚½‚çtrue
	return itr == m_enemys.end() ? false : true;
}
bool EnemyManager::reqestGoToMid()
{
	//MID‚Ì‚â‚Â‚ª‚¢‚é‚©ŒŸõ
	auto itr = std::find_if(m_enemys.begin(), m_enemys.end(), [](Enemy_Ptr& _e) {return _e->currentDistance() == EAI::MIDDRANGE; });
	//‹‚½‚çtrue
	return itr == m_enemys.end() ? false : true;
}