#pragma once
/**
* @file Stand.h
* @brief Player用Standステート
* @author 松尾裕也
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
	//クローンを作成する
	Player::StandState* clone() const override;
};