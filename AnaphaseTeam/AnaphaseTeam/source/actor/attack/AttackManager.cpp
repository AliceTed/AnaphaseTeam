#include "../../../header/actor/attack/attackManager.h"
#include "../../../header/actor/Player/Player.h"
#include "../../../header/shape/Sphere.h"




attackManager::attackManager()
	:m_Scythe(),
	m_Gun(),
	m_currentKey(),
	m_attackMap()
{
}

attackManager::~attackManager()
{
}

void attackManager::initialize()
{
	m_Scythe.initialize();
	m_Gun.initialize();
	m_attackMap.clear();
	Shape_Ptr sphere = std::make_shared<Sphere>(GSvector3(0, 0, 0), 0);
	ContinuationCombo combo(AttackStatus(0.0f, 0.0f, GSvector3(0, 0, 0)), ANIMATION_ID::ATTACK, sphere);
	m_attackMap.insert(std::make_pair(AttackKey::attack1, combo));
	ContinuationCombo combo2(AttackStatus(0.0f, 0.0f, GSvector3(0, 0, 0)), ANIMATION_ID::ATTACK2, sphere);
	m_attackMap.insert(std::make_pair(AttackKey::attack2, combo2));
}

void attackManager::update(Player* _player)
{
	scytheAttack(_player);
	gunAttack(_player);
}

void attackManager::scytheAttack(Player* _player)
{
	if (!m_Input->scytheTrigger())return;
	m_currentKey = AttackKey::attack1;
	m_attackMap.at(m_currentKey).anime(_player);
}

void attackManager::gunAttack(Player * _player)
{
	if (!m_Input->gunTrigger())return;
	m_currentKey = AttackKey::attack2;
	m_attackMap.at(m_currentKey).anime(_player);
}
bool attackManager::isEndAttack(Animator* _animator)
{
	return m_attackMap.at(m_currentKey).isEndAnimation(_animator);
}
