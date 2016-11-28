#pragma once
/**
* @file LimitFallState.h
* @brief Player用制限落下ステート
* @author 松尾裕也
* @date 2016/11/26
*/
#include "../../actor/Player/Player.h"
#include "../ActorState.h"
#include "../../subAction/Jumping.h"
class Player::LimitFallState :public ActorState<Player>
{
public:
	Player::LimitFallState(Player* _player);
private:
	void start()override;
	void action(float deltaTime)override;
	//クローンを作成する
	Player::LimitFallState* clone() const override;
private:
	Jumping m_jumping;
};
