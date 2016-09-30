#include "../../header/attack/attackManager.h"
#include "../../header/actor/Player/Player.h"

AttackManager::AttackManager()
	:m_Scythe(),
	m_Gun(),
	m_combo()
{
	
}

AttackManager::~AttackManager()
{
}

void AttackManager::initialize()
{
	m_Scythe.initialize();
	m_Gun.initialize();
	m_combo.initialize();
}
void AttackManager::update(float deltaTime, Player* _player, AnimatorOne* _animator)
{
	scytheAttack(deltaTime,_player,_animator);
	gunAttack(_player);
}

void AttackManager::scytheAttack(float deltaTime,Player* _player, AnimatorOne* _animator)
{
	m_combo.update(deltaTime, _player,_animator);
}

void AttackManager::gunAttack(Player * _player)
{
	if (_player->isGunAttack())
	{
		
	}
}

const bool AttackManager::isEnd() const
{
	return m_combo.isEnd();
}
