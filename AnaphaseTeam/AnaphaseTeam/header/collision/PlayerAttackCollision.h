#pragma once
#include "CollisionActor.h"
#include "../actor/Player/Player.h"
#include "../convenient/Timer.h"
class Player::PlayerAttackCollision:public CollisionActor
{
public:
	Player::PlayerAttackCollision(Player* _player);
private:
	void doUpdate(float deltaTime);
	void doDraw(IRenderer * _renderer);
	void collision_Enter(HitInformation& _hit);
private:
	Player* m_player;
	Timer m_destroy;
};