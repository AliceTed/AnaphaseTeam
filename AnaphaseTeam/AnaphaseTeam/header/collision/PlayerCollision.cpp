#include "../../header/collision/PlayerCollision.h"
#include "../../header/shape/Capsule.h"
#include "../../header/collision/HitInformation.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/actionstate/DamageState.h"

PlayerCollision::PlayerCollision(Player* _player)
	:CollisionActor(new Capsule(Segment(GSvector3(0, 0.2f, 0), GSvector3(0, 1.0f, 0)), 0.4f), Collision_Tag::PLAYER),
	m_player(_player)
{
}

PlayerCollision::~PlayerCollision()
{
}

void PlayerCollision::chase(const GSvector3 & _position)
{
	m_shape->transfer(_position + GSvector3(0, 0.2f, 0));
}

void PlayerCollision::doUpdate(float deltaTime)
{
	m_player->collisionChase(this);
}

void PlayerCollision::collision_Enter(HitInformation & _hit)
{
	if (_hit.m_tag == Collision_Tag::ENEMY_ATTACK)
	{
		m_player->actionChange(std::make_shared<DamageState>());
		m_player->hpDown();
	}
	
}

void PlayerCollision::doDraw(const Renderer & _renderer)
{
	//m_shape->draw(_renderer);
}
