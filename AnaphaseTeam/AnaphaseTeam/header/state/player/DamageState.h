#pragma once
/**
* @file DamageState.h
* @brief Player�p�_���[�W�X�e�[�g
* @author �����T��
* @date 2016/11/26
*/
#include "../../actor/Player/Player.h"
#include "../ActorState.h"
class Player::DamageState:public ActorState<Player>
{
public:
	Player::DamageState(Player* _player);
private:
	void start()override;
	void action(float deltaTime)override;
	//�N���[�����쐬����
	Player::DamageState* clone() const override;
};