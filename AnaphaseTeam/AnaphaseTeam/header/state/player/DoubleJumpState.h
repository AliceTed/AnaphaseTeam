#pragma once
/**
* @file DoubleJumpState.h
* @brief Player用2段目ジャンプステート
* @author 松尾裕也
* @date 2016/11/26
*/
#include "../../actor/Player/Player.h"
#include "../ActorState.h"
#include "../../subAction/Jumping.h"
class Player::DoubleJumpState :public ActorState<Player>
{
public:
	Player::DoubleJumpState(Player* _player);
private:
	void start()override;
	void action(float deltaTime)override;
	//クローンを作成する
	Player::DoubleJumpState* clone() const override;
private:
	Jumping m_jumping;
};
