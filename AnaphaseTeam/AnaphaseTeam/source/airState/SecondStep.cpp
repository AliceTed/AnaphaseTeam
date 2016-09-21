/**
* @file secondStep.cpp
* @brief ��i�W�����v�ڂ̃X�e�[�g
* @author �a�J�m��
* @date 2016/08/29
*/
#include "../../header/airstate/SecondStep.h"
#include "../../header/actor/Player/Player.h"
const float SecondStep::SecondStepPow = 1.0f;
SecondStep::SecondStep()
{

}
SecondStep::~SecondStep()
{

}
void SecondStep::start(JumpControl * _control)
{
	_control->start(SecondStepPow);
}
void SecondStep::airAction(JumpControl* _control, Player* _player, float deltaTime)
{
	_player->jumpUp();
	_control->jumping(_player, deltaTime);
	_player->movement(deltaTime);
}
void SecondStep::next(JumpControl * _control)
{

}