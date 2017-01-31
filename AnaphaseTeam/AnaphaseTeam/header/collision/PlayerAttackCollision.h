#pragma once
#include "CollisionActor.h"
#include "../actor/Player/Player.h"
#include "../convenient/Timer.h"

struct ShapeData;
class Player::PlayerAttackCollision:public CollisionActor
{
public:
	Player::PlayerAttackCollision(Player* _player, const ShapeData& _data, float _speed);
private:
	void doUpdate(float deltaTime);
	void doDraw(IRenderer * _renderer);
	void collision_Enter(HitInformation& _hit);
private:
	Player* m_player;
	Timer m_destroy;
	GSvector3 m_offset;
	float m_speed;
	GSvector3 p;
};