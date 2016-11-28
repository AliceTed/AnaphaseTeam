#include "../../header/subAction/subActionManager.h"
#include "../../header/actor/Player/Player.h"
subActionManager::subActionManager(Player* _player)
	:m_jump(_player), m_avoid(_player), m_current()
{
}
subActionManager::~subActionManager()
{
}

void subActionManager::initialize(SubActionType _type)
{
	switch (_type)
	{
	case SubActionType::JUMP:
		m_jump.initialize();
		break;
	case SubActionType::AVOID:
		m_avoid.initialize();
		break;
	}
	m_current = _type;
}

void subActionManager::update(float deltaTime, SubActionType _type)
{
	switch (_type)
	{
	case SubActionType::JUMP:
		m_jump.update(deltaTime);
		return;
	case SubActionType::AVOID:
		m_avoid.update(deltaTime);
		return;
	}	
}

const bool subActionManager::isEnd(SubActionType _type) const
{
	switch (_type)
	{
	case SubActionType::JUMP:
		return m_jump.isEnd();
	case SubActionType::AVOID:
		return m_avoid.isEnd();
	}
	return false;
}

/**
* @fn
* @brief ƒWƒƒƒ“ƒv—Í‚ð‚O‚É‚·‚é
*/
void subActionManager::jumpPowerOff()
{
	m_jump.setPower(0);
}
