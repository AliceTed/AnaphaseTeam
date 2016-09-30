/**
* @file firstStep.cpp
* @brief 一段ジャンプ目のステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#include "../../header/airstate/firstStep.h"
#include "../../header/airstate/secondStep.h"
#include "../../header/airstate/RestrictionFall.h"
#include "../../header/airstate/GroundState.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/math/Calculate.h"
#include "../../header/subAction/JumpControl.h"

#include "../../header/actionstate/AvoidState.h"
const float FirstStep::FirstStepPow = 0.6f;

FirstStep::FirstStep()
{

}

FirstStep::~FirstStep()
{

}

void FirstStep::start(JumpControl * _control, Player* _player)
{
	_player->startJump(_control,FirstStepPow);
}

void FirstStep::airAction(JumpControl* _control, Player* _player, float deltaTime)
{
	_player->jumpMotion(*_control,ANIMATION_ID::JUMPUP);
	_player->moving(deltaTime,false);
	_player->control();
	_player->avoidStart();
	_control->jumping(deltaTime, _player);
	change(_control, _player);
}

void FirstStep::change(JumpControl* _control, Player* _player)
{
	AirAction_Ptr action = next(_player);
	if (action == nullptr)return;
	_control->airActionChange(action);
}

AirAction_Ptr FirstStep::next(const Player * _player)const
{
	if (_player->isGround())
	{
		return std::make_shared<GroundState>();
	}

	if (_player->isJump())
	{
		return std::make_shared<SecondStep>();
	}
	
	return nullptr;
}
