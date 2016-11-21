#include "../../../../header/actor/Player/specialSkill/SpecialSkillManager.h"

SpecialSkillManager::SpecialSkillManager(Gauge& _gauge) :
	m_recovery(),
	m_superArmor(),
	m_gauge(_gauge),
	m_specialAttack(),
	m_spAttackUI()
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
	m_spAttackUI.update();
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

void SpecialSkillManager::draw(const Renderer & _renderer)
{
	int resetTime;
	resetTime = 0;

	m_spAttackUI.draw(_renderer);
	switch (m_type)
	{
	case SPECIALTYPE::NONE:
		break;
	case SPECIALTYPE::RECOVERY:
		m_spAttackUI.spChange(TEXTURE_ID::SP_UI1);
		resetTime++;
		break;
	case SPECIALTYPE::SUPERARMOR:
		m_spAttackUI.spChange(TEXTURE_ID::SP_UI2);
		resetTime++;
		break;
	case SPECIALTYPE::SPECIALATTACK:
		m_spAttackUI.spChange(TEXTURE_ID::SP_UI3);
		resetTime++;
		break;
	}
	if (resetTime >= 1)
	{
		m_type = SPECIALTYPE::NONE;
		resetTime = 0;
	}
}

bool SpecialSkillManager::isRbstate()
{
	return false;
}
