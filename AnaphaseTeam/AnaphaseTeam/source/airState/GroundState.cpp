/**
* @file groundState.cpp
* @brief 着地のステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#include "../../header/airstate/groundState.h"
#include "../../header/airstate/PreparationState.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/subAction/JumpControl.h"
GroundState::GroundState()
{

}
GroundState::~GroundState()
{

}
void GroundState::start(JumpControl * _control, Player* _player)
{

}
void GroundState::airAction(JumpControl* _control, Player* _player, float deltaTime)
{
	_player->moveStart();
	_player->control();
	_player->subActionStart();
	_player->jumpMotion(*_control, ANIMATION_ID::LANDING);
	if (_player->isAnimationEnd())
	{
		_control->end();
	}
}