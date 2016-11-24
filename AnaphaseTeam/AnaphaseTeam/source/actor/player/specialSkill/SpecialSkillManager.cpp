#include "../../../../header/actor/Player/specialSkill/SpecialSkillManager.h"
#include "../../../../header/actor/Player/Gauge.h"

SpecialSkillManager::SpecialSkillManager(Gauge& _gauge, Player* _player) :
	m_recovery(),
	m_superArmor(),
	m_gauge(_gauge),
	m_specialAttack(_player),
	m_spAttackUI()
{
}

SpecialSkillManager::~SpecialSkillManager()
{
}

bool SpecialSkillManager::initialize(SPECIALTYPE _specialType)
{
	switch (_specialType)
	{
	case SPECIALTYPE::NONE:
		break;
	case SPECIALTYPE::RECOVERY:
		if (isGaugeCheck((float)RankGauge::FIRST))
		{
		m_recovery.initialize(&m_gauge);
			return true;
		}
		break;
	case SPECIALTYPE::SUPERARMOR:
		if (isGaugeCheck((float)RankGauge::SECOND))
		{
		m_superArmor.initialize(&m_gauge);
			return true;
		}
		break;
	case SPECIALTYPE::SPECIALATTACK:
		if (isGaugeCheck((float)RankGauge::MAX))
		{
		m_specialAttack.initialize(&m_gauge);
			return true;
		}
		break;
	}
	m_type = _specialType;
	return false;
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
	return true;
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

void SpecialSkillManager::draw(IRenderer * _renderer)
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

void SpecialSkillManager::addAttackCollision(CollisionGroup * _group)
{
	m_specialAttack.addColision(_group);
}

bool SpecialSkillManager::isGaugeCheck(float _gauge)
{
	return m_gauge.nowGauge() >= _gauge;
}
