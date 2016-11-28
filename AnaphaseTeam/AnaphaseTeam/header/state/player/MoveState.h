#pragma once
/**
* @file MoveState.h
* @brief Player�p�ړ��X�e�[�g
* @author �����T��
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
	//�N���[�����쐬����
	Player::MoveState* clone() const override;
	//�e��Parameter�͕ύX���₷���悤�ɃN���X�ɂ܂Ƃ߂������悢����
	static const float SPEED;
};