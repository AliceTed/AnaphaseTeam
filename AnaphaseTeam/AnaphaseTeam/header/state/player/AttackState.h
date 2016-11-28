#pragma once
/**
* @file AttackState.h
* @brief Player�p�U���X�e�[�g 
* @author �����T��
* @date 2016/11/26
*/
#include "../../actor/Player/Player.h"
#include "../ActorState.h"
#include "../../convenient/Timer.h"
class Player::AttackState:public ActorState<Player>
{
public:
 	Player::AttackState(Player* _player);
private:
	void start()override;
	void action(float deltaTime)override;
	//�N���[�����쐬����
	Player::AttackState* clone() const override;
	void input(float deltaTime);
private:
	Timer m_inputTimer;
};