/**
* @file groundState.cpp
* @brief 着地のステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#include "../../header/airstate/groundState.h"
#include "../../header/airstate/PreparationState.h"
#include "../../header/actor/Player/Player.h"

GroundState::GroundState()
	:m_RigorTimer(0.3f)
{

}
GroundState::~GroundState()
{

}
void GroundState::start(JumpControl * _control, Player* _player)
{
	m_RigorTimer.initialize();
}
void GroundState::airAction(JumpControl* _control, Player* _player, float deltaTime)
{
	_player->jumpRigor();
	m_RigorTimer.update(deltaTime);
	if (m_RigorTimer.isEnd())
	{
		_control->end();
		//_control->airActionChange(std::make_shared<PreparationState>());
	}
}