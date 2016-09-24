/**
* @file firstStep.h
* @brief �d�������X�e�[�g
* @author �a�J�m��
* @date 2016/08/29
*/
#pragma once
#include "IAirState.h"
class RestrictionFall :public IAirState
{
public:
	RestrictionFall();
	~RestrictionFall();
	/**
	* @fn
	* @brief �W�����v�̗͂��O�ɂ���
	*/
	void start(JumpControl* _control, Player* _player);
	/**
	* @fn
	* @brief �W�����v��̗���
	*/
	void airAction(JumpControl* _control, Player* _player, float deltaTime);
private:
	void change(JumpControl* _control, Player* _player);
private:
	static const float Restriction;
};
