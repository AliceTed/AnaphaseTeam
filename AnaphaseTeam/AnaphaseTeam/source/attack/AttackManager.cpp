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
	m_combo.create();
	m_combo.initialize();
}
void AttackManager::update(float deltaTime, Player* _player)
{
	m_combo.update(deltaTime,_player);
	//scytheAttack(deltaTime,_player);
	//gunAttack(_player);
}

void AttackManager::scytheAttack(float deltaTime,Player* _player)
{
}

void AttackManager::gunAttack(Player * _player)
{
}

const bool AttackManager::isEndAttack() const
{
	return m_combo.isEnd();
}
