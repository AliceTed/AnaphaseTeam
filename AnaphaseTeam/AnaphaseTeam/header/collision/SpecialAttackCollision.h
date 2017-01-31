#pragma once
#include "CollisionActor.h"
#include "../actor/Player/Player.h"
#include "convenient\Timer.h"
class Player::SpecialAttackCollision :public CollisionActor
{
public:
	Player::SpecialAttackCollision(Player* _player);
private:
	void doUpdate(float deltaTime)override;

	//�ȉ��ꎞ�I�ȃe�X�g�p
	void doDraw(IRenderer * _renderer)override;
private:
	Player* m_player;
	Timer m_destroyTime;
};