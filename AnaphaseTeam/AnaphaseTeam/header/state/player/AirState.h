#pragma once
/**
* @file AirState.h
* @brief Player用空中ステート
* @author 松尾裕也
* @date 2016/11/26
*/
#include "../../actor/Player/Player.h"
#include "../ActorState.h"
class Player::AirState :public ActorState<Player>
{
public:
	Player::AirState(Player* _player);
private:
	void start()override;
	void action(float deltaTime)override;
	//クローンを作成する
	Player::AirState* clone() const override;

private:
	class GroundState;

};