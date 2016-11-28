#pragma once
/**
* @file LandingRigidityState.h
* @brief Player用着地硬直ステート
* @author 松尾裕也
* @date 2016/11/26
*/
#include "../../actor/Player/Player.h"
#include "../ActorState.h"
class Player::LandingRigidityState :public ActorState<Player>
{
public:
	Player::LandingRigidityState(Player* _player);
private:
	void start()override;
	void action(float deltaTime)override;
	//クローンを作成する
	Player::LandingRigidityState* clone() const override;
};
