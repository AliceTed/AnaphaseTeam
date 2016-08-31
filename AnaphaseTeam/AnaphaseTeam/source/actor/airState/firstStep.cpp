/**
* @file firstStep.cpp
* @brief 一段ジャンプ目のステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#include "../../../header/actor/airstate/firstStep.h"
#include "../../../header/actor/Player/Player.h"
#include "../../../header/actor/airstate/secondStep.h"

const float firstStep::FirstStepPow = 1.2f;
firstStep::firstStep()
{

}

firstStep::~firstStep()
{

}

void firstStep::start(jumpControl * _jumpAction)
{
	_jumpAction->start(FirstStepPow);
}

void firstStep::airAction(jumpControl* _jumpAction, Player* _player, float deltaTime)
{
	_player->jumpUp();
	_jumpAction->jumping(_player, deltaTime);
	_player->movement(deltaTime);
}

void firstStep::next(jumpControl * _control)
{
	_control->airActionChange(std::make_shared<secondStep>());
}
