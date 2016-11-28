#pragma once
#include "CollisionActor.h"
#include "../actor/Player/Player.h"
class Player::SpecialAttackCollision :public CollisionActor
{
public:
	Player::SpecialAttackCollision(Player* _player);
private:
	void doUpdate(float deltaTime)override;
	void doDraw(const Renderer& _renderer)override;
private:
	Player* m_player;
};