/**
* @file groundState.cpp
* @brief �n��ɂ���Ƃ��̃X�e�[�g
* @author �a�J�m��
* @date 2016/08/29
*/
#include "../../../header/actor/airstate/groundState.h"
#include "../../../header/actor/airstate/firstStep.h"

GroundState::GroundState()
{

}
GroundState::~GroundState()
{

}
void GroundState::start(JumpControl * _jumpAction)
{
}
void GroundState::airAction(JumpControl* _jumpAction, Player* _player, float deltaTime)
{
}
void GroundState::next(JumpControl * _control)
{
	_control->airActionChange(std::make_shared<FirstStep>());
}