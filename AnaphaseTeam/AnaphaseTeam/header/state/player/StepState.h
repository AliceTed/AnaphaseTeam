#pragma once
/**
* @file StepState.h
* @brief Player用Stepステート
* @author 松尾裕也
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
	//クローンを作成する
	Player::StepState* clone() const override;
	void tracking();
private:
	Step m_step;

	float m_velocity;
};