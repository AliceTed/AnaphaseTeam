/**
* @file firstStep.cpp
* @brief 一段ジャンプ目のステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#include "../../../header/actor/airstate/firstStep.h"
#include "../../../header/actor/Player/Player.h"
#include "../../../header/actor/airstate/secondStep.h"

const float FirstStep::FirstStepPow = 1.2f;
FirstStep::FirstStep()
{

}
FirstStep::~FirstStep()
{

}
void FirstStep::start(JumpControl * _jumpAction)
{
	_jumpAction->start(FirstStepPow);
}
void FirstStep::airAction(JumpControl* _jumpAction, Player* _player, float deltaTime)
{
	_player->jumpUp();
	_jumpAction->jumping(_player, deltaTime);
	_player->movement(deltaTime);
}
void FirstStep::next(JumpControl * _control)
{
	_control->airActionChange(std::make_shared<SecondStep>());
}