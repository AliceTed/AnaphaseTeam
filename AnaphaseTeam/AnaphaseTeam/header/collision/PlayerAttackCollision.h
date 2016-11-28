#pragma once
#include "CollisionActor.h"
#include "../actor/Player/Player.h"
class Player::PlayerAttackCollision:public CollisionActor
{
public:
	Player::PlayerAttackCollision(Player* _player);
private:
	void doUpdate(float deltaTime);
	void doDraw(const Renderer& _renderer);
	void collision_Enter(HitInformation& _hit);
private:
	Player* m_player;
};