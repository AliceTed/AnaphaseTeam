/**
* @file groundState.cpp
* @brief �n��ɂ���Ƃ��̃X�e�[�g
* @author �a�J�m��
* @date 2016/08/29
*/
#include "../../header/airstate/groundState.h"
#include "../../header/airstate/firstStep.h"

GroundState::GroundState()
{

}
GroundState::~GroundState()
{

}
void GroundState::start(JumpControl * _control)
{
}
void GroundState::airAction(JumpControl* _control, Player* _player, float deltaTime)
{
}
void GroundState::next(JumpControl * _control)
{
	_control->airActionChange(std::make_shared<FirstStep>());
}