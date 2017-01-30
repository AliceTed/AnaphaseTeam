#pragma once
/**
* @file SpecialAttackState.h
* @brief Player用特殊攻撃ステート
* @author 松尾裕也
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
	//クローンを作成する
	Player::SpecialAttackState* clone() const override;

private:
	Timer m_spawnTimer;
};