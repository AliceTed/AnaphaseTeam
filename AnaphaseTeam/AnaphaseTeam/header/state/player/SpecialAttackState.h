#pragma once
/**
* @file SpecialAttackState.h
* @brief Player�p����U���X�e�[�g
* @author �����T��
* @date 2016/12/01
*/
#include "../../actor/Player/Player.h"
#include "../ActorState.h"
#include "convenient/Timer.h"
class Player::SpecialAttackState:public ActorState<Player>
{
public:
	Player::SpecialAttackState(Player* _player);
private:
	void start()override;
	void action(float deltaTime)override;
	//�N���[�����쐬����
	Player::SpecialAttackState* clone() const override;

private:
	Timer m_spawnTimer;
};