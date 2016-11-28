#pragma once
/**
* @file AttackState.h
* @brief Player用攻撃ステート 
* @author 松尾裕也
* @date 2016/11/26
*/
#include "../../actor/Player/Player.h"
#include "../ActorState.h"
#include "../../convenient/Timer.h"
class Player::AttackState:public ActorState<Player>
{
public:
 	Player::AttackState(Player* _player);
private:
	void start()override;
	void action(float deltaTime)override;
	//クローンを作成する
	Player::AttackState* clone() const override;
	void input(float deltaTime);
private:
	Timer m_inputTimer;
};