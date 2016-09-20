#include "../../../header/actor/attack/attackManager.h"
#include "../../../header/actor/Player/Player.h"
#include "../../../header/shape/Sphere.h"




AttackManager::AttackManager()
	:m_Scythe(),
	m_Gun(),
	m_currentKey(),
	m_Pattern()
{
}

AttackManager::~AttackManager()
{
}

void AttackManager::initialize()
{
	m_Scythe.initialize();
	m_Gun.initialize();
	m_Pattern.clear();
	Shape_Ptr sphere = std::make_shared<Sphere>(GSvector3(0, 0, 0), 0);
	ContinuationCombo combo(AttackStatus(0.0f, 0.0f, GSvector3(0, 0, 0)), ANIMATION_ID::ATTACK, sphere);
	m_Pattern.insert(std::make_pair(AttackPattern::ScytheAttack1, combo));
	ContinuationCombo combo2(AttackStatus(0.0f, 0.0f, GSvector3(0, 0, 0)), ANIMATION_ID::ATTACK2, sphere);
	m_Pattern.insert(std::make_pair(AttackPattern::GunAttack, combo2));
}

void AttackManager::update(Player* _player)
{
	scytheAttack(_player);
	gunAttack(_player);
}

void AttackManager::scytheAttack(Player* _player)
{
	if (!m_Input->scytheTrigger())return;
	m_currentKey = AttackPattern::ScytheAttack1;
	m_Pattern.at(m_currentKey).anime(_player);
}

void AttackManager::gunAttack(Player * _player)
{
	if (!m_Input->gunTrigger())return;
	m_currentKey = AttackPattern::GunAttack;
	m_Pattern.at(m_currentKey).anime(_player);
}
bool AttackManager::isEndAttack(Animator* _animator)
{
	return m_Pattern.at(m_currentKey).isEndAnimation(_animator);
}
