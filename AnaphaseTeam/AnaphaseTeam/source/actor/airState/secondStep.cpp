/**
* @file secondStep.cpp
* @brief 二段ジャンプ目のステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#include "../../../header/actor/airstate/secondStep.h"
#include "../../../header/actor/Player/Player.h"
const float secondStep::SecondStepPow = 1.0f;
secondStep::secondStep()
{

}

secondStep::~secondStep()
{

}

void secondStep::start(jumpControl * _jumpAction)
{
	_jumpAction->start(SecondStepPow);
}

void secondStep::airAction(jumpControl* _jumpAction, Player* _player, float deltaTime)
{
	_player->jumpUp();
	_jumpAction->jumping(_player, deltaTime);
	_player->movement(deltaTime);
}

void secondStep::next(jumpControl * _control)
{

}
