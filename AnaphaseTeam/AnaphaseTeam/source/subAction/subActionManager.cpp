#include "../../header/subAction/subActionManager.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/actor/airstate/groundState.h"
#include "../../header/actor/airstate/RestrictionFall.h"
subActionManager::subActionManager()
	:m_jump(), m_chainMove()
{
}

subActionManager::~subActionManager()
{
}

void subActionManager::jumpInitialize()
{
	m_jump.airActionChange(std::make_shared<groundState>());
}

void subActionManager::action(Player * _player, float deltaTime)
{
	//m_jump.jumping(_player, deltaTime);
	m_jump.update(_player, deltaTime);
	//m_chainMove.movement(deltaTime, _player);
}

//void subActionManager::actionStart(Player * _player)
//{
//	//_player->subActionStart(&m_jump, &m_chainMove);
//}

void subActionManager::groundHit()
{
	//m_jump.airActionChange(std::make_shared<groundState>());
	m_jump.groundHit();
}

void subActionManager::jumpStart()
{
	m_jump.jump();
}

void subActionManager::chainMoveStart()
{
	m_chainMove.start();
}

void subActionManager::restrictionFall()
{
	m_jump.airActionChange(std::make_shared<RestrictionFall>());
}
