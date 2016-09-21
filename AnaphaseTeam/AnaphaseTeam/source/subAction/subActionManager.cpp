#include "../../header/subAction/subActionManager.h"
#include "../../header/actor/Player/Player.h"
subActionManager::subActionManager(Player* _player)
	:m_jump(_player)
{
}
subActionManager::~subActionManager()
{
}

void subActionManager::initialize()
{
	m_jump.initialize();
}

void subActionManager::update(float deltaTime)
{
	m_jump.update(deltaTime);
}

const bool subActionManager::isEnd() const
{
	return m_jump.isEnd();
}
