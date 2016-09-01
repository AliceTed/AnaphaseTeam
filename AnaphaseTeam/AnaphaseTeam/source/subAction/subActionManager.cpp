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
	m_jump.airActionChange(std::make_shared<GroundState>());
}
void subActionManager::action(Player * _player, float deltaTime)
{
	m_jump.update(_player, deltaTime);
	//m_chainMove.movement(deltaTime, _player);
}
void subActionManager::groundHit()
{
	m_jump.groundHit();
}
//���݂̃W�����v�X�e�[�g���玟�̃W�����v�X�e�[�g�ֈڍs
void subActionManager::jumpStart()
{
	m_jump.jump();
}
void subActionManager::chainMoveStart()
{
	m_chainMove.start();
}
//�d������
void subActionManager::restrictionFall()
{
	m_jump.airActionChange(std::make_shared<RestrictionFall>());
}