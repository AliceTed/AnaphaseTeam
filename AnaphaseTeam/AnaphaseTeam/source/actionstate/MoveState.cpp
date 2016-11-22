/**
* @file MoveState.cpp
* @brief �ړ��̃X�e�[�g
* @author �a�J�m��
* @date 2016/08/29
*/
#include "../../header/actionstate/MoveState.h"
#include "../../header/actor/ICharacter.h"


MoveState::MoveState()
{
}

MoveState::~MoveState()
{
}

void MoveState::action(ICharacter* _actor,float deltaTime)
{
	_actor->move(deltaTime);
}