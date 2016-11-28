#pragma once
/**
* @file SingleJumpState.h
* @brief Player用1段目ジャンプステート
* @author 松尾裕也
* @date 2016/11/26
*/
#include "../../actor/Player/Player.h"
#include "../ActorState.h"
#include "../../subAction/Jumping.h"
class Player::SingleJumpState :public ActorState<Player>
{
public:
	Player::SingleJumpState(Player* _player);
private:
	void start()override;
	void action(float deltaTime)override;
	//クローンを作成する
	Player::SingleJumpState* clone() const override;
private:
	Jumping m_jumping;
};