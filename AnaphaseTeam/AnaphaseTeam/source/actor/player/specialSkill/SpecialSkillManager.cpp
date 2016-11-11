#include "../../../../header/actor/Player/specialSkill/SpecialSkillManager.h"

SpecialSkillManager::SpecialSkillManager() :
	m_recovery()
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
		m_recovery.initialize();
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
	}
}
void SpecialSkillManager::recovery(Status& _status)
{
	if (m_type == SPECIALTYPE::RECOVERY)
		m_recovery.add(_status);
}
