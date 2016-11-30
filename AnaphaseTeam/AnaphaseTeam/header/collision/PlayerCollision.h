#pragma once
#include "CollisionActor.h"
#include "../actor/Player/Player.h"
class Player::PlayerCollision :public CollisionActor
{
public:
	Player::PlayerCollision(Player* _player);
	void doUpdate(float deltaTime)override;
	void collision_Enter(HitInformation& _hit)override;
	void doDraw(IRenderer *_renderer)override;
private:
	Player* m_player;
};