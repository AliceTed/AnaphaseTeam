#pragma once
/**
* @file MoveState.h
* @brief Player用移動ステート
* @author 松尾裕也
* @date 2016/11/26
*/
#include "../../actor/Player/Player.h"
#include "../ActorState.h"
class Player::MoveState :public ActorState<Player>
{
public:
	Player::MoveState(Player* _player);
private:
	void start()override;
	void action(float deltaTime)override;
	//クローンを作成する
	Player::MoveState* clone() const override;
	//各種Parameterは変更しやすいようにクラスにまとめた方がよいかも
	static const float SPEED;
};