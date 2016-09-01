/**
* @file secondStep.cpp
* @brief ��i�W�����v�ڂ̃X�e�[�g
* @author �a�J�m��
* @date 2016/08/29
*/
#include "../../../header/actor/airstate/secondStep.h"
#include "../../../header/actor/Player/Player.h"
const float SecondStep::SecondStepPow = 1.0f;
SecondStep::SecondStep()
{

}
SecondStep::~SecondStep()
{

}
void SecondStep::start(JumpControl * _jumpAction)
{
	_jumpAction->start(SecondStepPow);
}
void SecondStep::airAction(JumpControl* _jumpAction, Player* _player, float deltaTime)
{
	_player->jumpUp();
	_jumpAction->jumping(_player, deltaTime);
	_player->movement(deltaTime);
}
void SecondStep::next(JumpControl * _control)
{

}