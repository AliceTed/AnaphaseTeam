/**
* @file firstStep.h
* @brief �d�������X�e�[�g
* @author �a�J�m��
* @date 2016/08/29
*/
#pragma once
#include "IAirState.h"
typedef std::shared_ptr<IAirState> AirAction_Ptr;
class RestrictionFall :public IAirState
{
public:
	RestrictionFall(JumpControl* _control, Player* _player);
	~RestrictionFall();
	/**
	* @fn
	* @brief �W�����v�̗͂��O�ɂ���
	*/
	void start();
	/**
	* @fn
	* @brief �W�����v��̗���
	*/
	void update(float deltaTime);
	const bool isEnd() const;
	std::shared_ptr<IAirState> next() const;
private:
	void change();
private:
	static const float Restriction;
	bool m_isEnd;
	AirAction_Ptr m_next;
	JumpControl* m_control;
	Player* m_player;
};
