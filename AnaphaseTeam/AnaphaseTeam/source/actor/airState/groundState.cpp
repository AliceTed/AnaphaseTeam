/**
* @file groundState.cpp
* @brief �n��ɂ���Ƃ��̃X�e�[�g
* @author �a�J�m��
* @date 2016/08/29
*/
#include "../../../header/actor/airstate/groundState.h"

groundState::groundState()
{

}

groundState::~groundState()
{

}

void groundState::airAction(jumpControl* _jumpAction)
{
	_jumpAction->groundHit();
}