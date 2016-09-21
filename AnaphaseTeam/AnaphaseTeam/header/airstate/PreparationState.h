/**
* @file firstStep.h
* @brief �W�����v�̏����X�e�[�g
* @author �a�J�m��
* @date 2016/09/21
*/
#pragma once
#include "IAirState.h"
class PreparationState :public IAirState
{
public:
	PreparationState();
	~PreparationState();
	/**
	* @fn
	* @brief 
	*/
	void start(JumpControl* _control, Player* _player);
	/**
	* @fn
	* @brief 
	*/
	void airAction(JumpControl* _control, Player* _player, float deltaTime);
};