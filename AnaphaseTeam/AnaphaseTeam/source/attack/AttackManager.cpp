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
	m_combo.initialize();
}

void AttackManager::update(float deltaTime, Player* _player)
{
	m_combo.update(deltaTime, _player);
}

const bool AttackManager::isEnd() const
{
	return m_combo.isEnd();
}

void AttackManager::Start(bool _attackChange, Player* _player)
{
	m_combo.start(_attackChange, _player);
}

float AttackManager::getStatus()
{
	return m_combo.isPower();
}
