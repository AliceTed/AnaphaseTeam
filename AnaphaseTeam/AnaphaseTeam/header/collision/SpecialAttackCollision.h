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

	//以下一時的なテスト用
	void doDraw(IRenderer * _renderer)override;
private:
	Player* m_player;
	Timer m_destroyTime;
};