#pragma once
/**
* @file AirState.h
* @brief Player�p�󒆃X�e�[�g
* @author �����T��
* @date 2016/11/26
*/
#include "../../actor/Player/Player.h"
#include "../ActorState.h"
class Player::AirState :public ActorState<Player>
{
public:
	Player::AirState(Player* _player);
private:
	void start()override;
	void action(float deltaTime)override;
	//�N���[�����쐬����
	Player::AirState* clone() const override;

private:
	class GroundState;

};