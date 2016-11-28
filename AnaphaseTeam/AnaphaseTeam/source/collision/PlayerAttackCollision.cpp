#include "..\..\header\collision\PlayerAttackCollision.h"
#include "../../header/shape/Sphere.h"
#include "../../header/actor/Player/Player.h"
Player::PlayerAttackCollision::PlayerAttackCollision(Player* _player)
	:CollisionActor(new Sphere(_player->target,0.7f),Collision_Tag::PLAYER_WEAPON),
	m_player(_player)
{
}

void Player::PlayerAttackCollision::doUpdate(float deltaTime)
{
	if (m_player->m_animatorOne.isEndCurrentAnimation())
	{
		destroy();
	}
}

void Player::PlayerAttackCollision::doDraw(const Renderer & _renderer)
{
	m_shape->draw(_renderer);
}

void Player::PlayerAttackCollision::collision_Enter(HitInformation & _hit)
{
}
