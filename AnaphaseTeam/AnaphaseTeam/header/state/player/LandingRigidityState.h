#pragma once
/**
* @file LandingRigidityState.h
* @brief Player�p���n�d���X�e�[�g
* @author �����T��
* @date 2016/11/26
*/
#include "../../actor/Player/Player.h"
#include "../ActorState.h"
class Player::LandingRigidityState :public ActorState<Player>
{
public:
	Player::LandingRigidityState(Player* _player);
private:
	void start()override;
	void action(float deltaTime)override;
	//�N���[�����쐬����
	Player::LandingRigidityState* clone() const override;
};
