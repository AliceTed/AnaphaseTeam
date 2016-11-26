#pragma once
/**
* @file DamageState.h
* @brief Player用ダメージステート
* @author 松尾裕也
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
	//クローンを作成する
	Player::DamageState* clone() const override;
};