#include "../../../../header/actor/Player/specialSkill/SpecialSkillManager.h"

SpecialSkillManager::SpecialSkillManager(Gauge& _gauge) :
	m_recovery(),
	m_superArmor(),
	m_gauge(_gauge),
	m_specialAttack()
{
}

SpecialSkillManager::~SpecialSkillManager()
{
}

void SpecialSkillManager::initialize(SPECIALTYPE _specialType)
{
	switch (_specialType)
	{
	case SPECIALTYPE::NONE:
		break;
	case SPECIALTYPE::RECOVERY:
		m_recovery.initialize(&m_gauge);
		break;
	case SPECIALTYPE::SUPERARMOR:
		m_superArmor.initialize(&m_gauge);
		break;
	case SPECIALTYPE::SPECIALATTACK:
		m_specialAttack.initialize(&m_gauge);
		break;
	}
	m_type = _specialType;

}

void SpecialSkillManager::update(float deltaTime)
{
	switch (m_type)
	{
	case SPECIALTYPE::NONE:
		break;
	case SPECIALTYPE::RECOVERY:
		m_recovery.update(deltaTime);
		break;
	case SPECIALTYPE::SUPERARMOR:
		m_superArmor.update(deltaTime);
		break;
	case SPECIALTYPE::SPECIALATTACK:
		m_specialAttack.update(deltaTime);
		break;
	}
}
const bool SpecialSkillManager::isEnd(SPECIALTYPE _specialType) const
{
	switch (_specialType)
	{
	case SPECIALTYPE::NONE:
		break;
	case SPECIALTYPE::RECOVERY:
		return m_recovery.isEnd();
		break;
	case SPECIALTYPE::SUPERARMOR:
		return m_superArmor.isEnd();
		break;
	case SPECIALTYPE::SPECIALATTACK:
		return m_specialAttack.isEnd();
		break;
	}
}
void SpecialSkillManager::recovery(Status& _status)
{
	if (m_type == SPECIALTYPE::RECOVERY)
		m_recovery.add(_status);
}

bool SpecialSkillManager::isSuperArmor()
{
	return m_superArmor.isSuperArmor();
}
