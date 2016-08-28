#include "../../header/subAction/subActionManager.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/actor/airstate/groundState.h"
subActionManager::subActionManager()
	:m_jump(), m_chainMove()
{
}

subActionManager::~subActionManager()
{
}

void subActionManager::action(Player * _player, float deltaTime)
{
	m_jump.jumping(_player, deltaTime);
	m_chainMove.movement(deltaTime, _player);
}

void subActionManager::actionStart(Player * _player)
{
	_player->subActionStart(&m_jump, &m_chainMove);
}

void subActionManager::groundHit()
{
	//m_jump.groundHit();
	m_jump.airActionChange(std::make_shared<groundState>());
}

const bool subActionManager::isfirstJump() const
{
	return m_jump.isfirstJump();
}