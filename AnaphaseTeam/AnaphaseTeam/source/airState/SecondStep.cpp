/**
* @file secondStep.cpp
* @brief 二段ジャンプ目のステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#include "../../header/airstate/SecondStep.h"
#include "../../header/airstate/RestrictionFall.h"
#include "../../header/airstate/GroundState.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/math/Calculate.h"
#include "../../header/subAction/JumpControl.h"
const float SecondStep::SecondStepPow = 0.5f;
SecondStep::SecondStep()
{

}
SecondStep::~SecondStep()
{

}
void SecondStep::start(JumpControl * _control, Player* _player)
{
	_player->startJump(_control, SecondStepPow);
}
void SecondStep::airAction(JumpControl* _control, Player* _player, float deltaTime)
{
	_player->jumpMotion(*_control,ANIMATION_ID::JUMPUP);
	_player->moving(deltaTime,false);
	_control->jumping(deltaTime, _player);
	_player->control();
	change(_control, _player);
}

void SecondStep::change(JumpControl * _control, Player * _player)
{
	AirAction_Ptr action = next(_player);
	if (action == nullptr)return;
	_control->airActionChange(action);
}

AirAction_Ptr SecondStep::next(const Player * _player) const
{
	if (_player->isGround())
	{
		return std::make_shared<GroundState>();
	}

	if (_player->isJumpAttack())
	{
		return std::make_shared<RestrictionFall>();
	}
	return nullptr;
}
