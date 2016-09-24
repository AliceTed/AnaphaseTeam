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
	m_combo.initilize();
}


void AttackManager::update(float deltaTime, Player* _player)
{
	m_combo.update(deltaTime,_player);
	scytheAttack(deltaTime,_player);
	gunAttack(_player);
}

void AttackManager::scytheAttack(float deltaTime,Player* _player)
{
	if (!m_Input->scytheTrigger())return;
	m_combo.combo(deltaTime);
}

void AttackManager::gunAttack(Player * _player)
{
	if (!m_Input->gunTrigger())return;

}

const bool AttackManager::isEndAttack(const AnimatorOne* _animator) const
{
	return m_combo.isCurrentEnd(_animator);
}
