#pragma once
/**
* @file StepState.h
* @brief Player�pStep�X�e�[�g
* @author �����T��
* @date 2016/11/26
*/
#include "../../actor/Player/Player.h"
#include "../ActorState.h"
#include "../../subAction/Step.h"
class Player::StepState :public ActorState<Player>
{
public:
	Player::StepState(Player* _player);
private:
	void start()override;
	void action(float deltaTime)override;
	//�N���[�����쐬����
	Player::StepState* clone() const override;
	void tracking();
private:
	Step m_step;

	float m_velocity;
};