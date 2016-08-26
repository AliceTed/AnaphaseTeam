#include "../../header/subAction/SubActionManager.h"
#include "../../header/actor/Player/Player.h"
SubActionManager::SubActionManager()
	:m_jump(),m_chainMove()
{
}

SubActionManager::~SubActionManager()
{
}

void SubActionManager::action(Player * _player, float deltaTime)
{
	m_jump.jumping(_player, deltaTime);
	m_chainMove.movement(deltaTime, _player);
}

void SubActionManager::actionStart(Player * _player)
{
	_player->subActionStart(&m_jump,&m_chainMove);
}

void SubActionManager::groundHit()
{
	m_jump.groundHit();
}
