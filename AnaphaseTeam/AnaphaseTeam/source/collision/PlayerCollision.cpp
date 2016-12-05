#include "../../header/collision/PlayerCollision.h"
#include "../../header/shape/Capsule.h"
#include "../../header/collision/HitInformation.h"
#include "../../header/actor/Player/Player.h"
Player::PlayerCollision::PlayerCollision(Player* _player)
	:CollisionActor(new Capsule(Segment(GSvector3(0, 0.2f, 0), GSvector3(0, 1.0f, 0)), 0.4f), Collision_Tag::PLAYER),
	m_player(_player)
{
}
void Player::PlayerCollision::doUpdate(float deltaTime)
{
	m_shape->transfer(m_player->m_transform.m_translate + GSvector3(0, 0.2f, 0));
}

void Player::PlayerCollision::collision_Enter(HitInformation & _hit)
{
	if (_hit.m_tag != Collision_Tag::ENEMY_ATTACK)return;
	//エネミーがダメージを食らったかチェックをしろ

	if (!m_player->m_specialskill.isStart(SPECIALSKILL_TYPE::SUPERARMOR))
	{
		m_player->changeState(ACTOR_STATE::DAMAGE);
	}
}

void Player::PlayerCollision::doDraw(IRenderer *_renderer)
{
	//m_shape->draw(_renderer);
}
