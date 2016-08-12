#pragma once
/**
*@file Player.h
*@drief �v���C���[�N���X
*@author �v�H��
*@date 2016/08/12
*/
#include "../Actor.h"
#include "../IActionState.h"
#include <memory>

typedef std::shared_ptr<IActionState> Action_Ptr;
class Player :public Actor
{
public:
	Player();
	~Player();
	void initialize();
	void update();
	void draw();
	void finish();
	void stand();
	void move();
	void attack();
	void damage();
	/**
	* @fn
	* @brief �A�N�V�����X�e�[�g�̐؂�ւ��֐�
	* @param (_action) �؂�ւ���A�N�V������Shared_ptr
	*/
	void actionChange(Action_Ptr _action);
private:
	Action_Ptr m_action;
};