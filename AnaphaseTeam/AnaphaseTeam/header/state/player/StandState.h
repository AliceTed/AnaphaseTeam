#pragma once
/**
* @file Stand.h
* @brief Player�pStand�X�e�[�g
* @author �����T��
* @date 2016/11/26
*/
#include "../../actor/Player/Player.h"
#include "../ActorState.h"
class Player::StandState:public ActorState<Player>
{
public:
	Player::StandState(Player* _player);
private:
	void start()override;
	void action(float deltaTime)override;
	//�N���[�����쐬����
	Player::StandState* clone() const override;
};