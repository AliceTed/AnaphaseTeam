#include "actor/Enemy/EnemyManager.h"
#include "actor/Player/Player.h"
#include <algorithm>
#include "camera/LockOn.h"
#include "actor/Enemy/IEnemy.h"
#include "map/Map.h"
#include "ui/UIManager.h"
#include "stage/Stage.h"
EnemyManager::EnemyManager(Player* _player, Score & _score)
	:m_enemys(),
	m_player(_player),
	m_score(_score)
{
}

void EnemyManager::initialize()
{
	m_enemys.clear();
}

void EnemyManager::add(IEnemy * _enemy)
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
	for (auto& i : m_enemys) { i->update(deltaTime);}
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

std::weak_ptr<IEnemy> EnemyManager::nearEnemy(Player * _player)
{
	std::sort(m_enemys.begin(), m_enemys.end(), [_player](Enemy_Ptr& _x, Enemy_Ptr& _y) {return _x->distanceActor(*_player) < _y->distanceActor(*_player); });
	if (m_enemys.empty())
	{
		return std::weak_ptr<IEnemy>();
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

void EnemyManager::addScore(int _score)
{
	m_score.add(_score);
}

float EnemyManager::requestDistancePlayer(IEnemy * _enemy)
{
	return _enemy->distanceActor(*m_player);
}
GSquaternion EnemyManager::requestPlayerDirection(IEnemy * _enemy)
{
	return _enemy->targetDirection(*m_player);
}
bool EnemyManager::requestDistanceOtherEnemy(IEnemy * _enemy)
{
	return false;
}

bool EnemyManager::isExist(EAI _range)
{
	//引数の距離に他のエネミーがいるか検索
	auto itr = std::find_if(m_enemys.begin(), m_enemys.end(), [&](Enemy_Ptr& _e) {return _e->currentAIRange() == _range; });
	//居たらtrue
	return itr == m_enemys.end() ? false : true;
}
bool EnemyManager::reqestGoToNear()
{
	//NEARのやつがいるか検索
	auto itr = std::find_if(m_enemys.begin(), m_enemys.end(), [](Enemy_Ptr& _e) {return _e->currentAIRange() == EAI::ATTACKRANGE; });
	//居たらtrue
	return itr == m_enemys.end() ? false : true;
}
bool EnemyManager::reqestGoToMid()
{
	//MIDのやつがいるか検索
	auto itr = std::find_if(m_enemys.begin(), m_enemys.end(), [](Enemy_Ptr& _e) {return _e->currentAIRange() == EAI::MIDDRANGE; });
	//居たらtrue
	return itr == m_enemys.end() ? false : true;
}