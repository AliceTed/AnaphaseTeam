#pragma once
/**
* @file SingleJumpState.h
* @brief Player�p1�i�ڃW�����v�X�e�[�g
* @author �����T��
* @date 2016/11/26
*/
#include "../../actor/Player/Player.h"
#include "../ActorState.h"
#include "../../subAction/Jumping.h"
class Player::SingleJumpState :public ActorState<Player>
{
public:
	Player::SingleJumpState(Player* _player);
private:
	void start()override;
	void action(float deltaTime)override;
	//�N���[�����쐬����
	Player::SingleJumpState* clone() const override;
private:
	Jumping m_jumping;
};