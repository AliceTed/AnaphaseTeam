#pragma once
/**
* @file DoubleJumpState.h
* @brief Player�p2�i�ڃW�����v�X�e�[�g
* @author �����T��
* @date 2016/11/26
*/
#include "../../actor/Player/Player.h"
#include "../ActorState.h"
#include "../../subAction/Jumping.h"
class Player::DoubleJumpState :public ActorState<Player>
{
public:
	Player::DoubleJumpState(Player* _player);
private:
	void start()override;
	void action(float deltaTime)override;
	//�N���[�����쐬����
	Player::DoubleJumpState* clone() const override;
private:
	Jumping m_jumping;
};
