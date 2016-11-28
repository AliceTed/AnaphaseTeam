#include "..\..\header\collision\PlayerAttackCollision.h"
#include "../../header/shape/Sphere.h"
#include "../../header/actor/Player/Player.h"
Player::PlayerAttackCollision::PlayerAttackCollision(Player* _player)
	:CollisionActor(new Sphere(_player->m_transform.m_translate,0.7f),Collision_Tag::PLAYER_WEAPON),
	m_player(_player),
	m_destroy(_player->m_animatorOne.getNextAnimationEndTime()/60.0f)
{
}

void Player::PlayerAttackCollision::doUpdate(float deltaTime)
{
	GSvector3 pos = m_player->m_transform.m_translate + m_player->m_transform.front() + GSvector3(0, 1, 0);
	m_shape->transfer(pos);
	m_destroy.update(deltaTime*m_player->m_status.attackSpeed());
	if (m_destroy.isEnd())
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
