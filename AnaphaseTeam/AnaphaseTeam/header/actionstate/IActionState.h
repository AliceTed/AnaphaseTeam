/**
* @file IActionState.h
* @brief �A�N�V�����X�e�[�g
* @author �a�J�m��
* @date 2016/08/29
*/
#pragma once
__interface ICharacter;
__interface IActionState
{
public:
	void action(ICharacter* _actor,float deltatime) = 0;
};