#pragma once
#include "CollisionActor.h"
#include "../transform/Transform.h"
//***機能確認用
#include <string>
//**
class Player;

class PlayerCollision :public CollisionActor
{
public:
	PlayerCollision(Player* _player);
	~PlayerCollision();
	void chase(const GSvector3& _position);
private:
	void doUpdate(float deltaTime)override;
	void collision_Enter(HitInformation& _hit)override;
	void doDraw(const Renderer& _renderer)override;
private:
	GSvector3 m_position;
	Player* m_player;
};