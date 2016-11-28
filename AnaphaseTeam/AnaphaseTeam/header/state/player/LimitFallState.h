#pragma once
/**
* @file LimitFallState.h
* @brief Player�p���������X�e�[�g
* @author �����T��
* @date 2016/11/26
*/
#include "../../actor/Player/Player.h"
#include "../ActorState.h"
#include "../../subAction/Jumping.h"
class Player::LimitFallState :public ActorState<Player>
{
public:
	Player::LimitFallState(Player* _player);
private:
	void start()override;
	void action(float deltaTime)override;
	//�N���[�����쐬����
	Player::LimitFallState* clone() const override;
private:
	Jumping m_jumping;
};
