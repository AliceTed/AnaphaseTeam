/**
* @file firstStep.h
* @brief �d�������X�e�[�g
* @author �a�J�m��
* @date 2016/08/29
*/
#pragma once
#include "IAirState.h"
#include "jumpControl.h"
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
	AirAction_Ptr next(const Player* _player) const;
private:
	static const float Restriction;
};
