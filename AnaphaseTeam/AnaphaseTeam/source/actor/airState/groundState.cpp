/**
* @file groundState.cpp
* @brief �n��ɂ���Ƃ��̃X�e�[�g
* @author �a�J�m��
* @date 2016/08/29
*/
#include "../../../header/actor/airstate/groundState.h"
#include "../../../header/actor/airstate/firstStep.h"

groundState::groundState()
{

}
groundState::~groundState()
{

}
void groundState::start(JumpControl * _jumpAction)
{
}
void groundState::airAction(JumpControl* _jumpAction, Player* _player, float deltaTime)
{
}
void groundState::next(JumpControl * _control)
{
	_control->airActionChange(std::make_shared<firstStep>());
}