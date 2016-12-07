#include "..\..\header\collision\PlayerAttackCollision.h"
#include "../../header/shape/Sphere.h"
#include "../../header/collision/HitInformation.h"
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

void Player::PlayerAttackCollision::doDraw(IRenderer *_renderer)
{
	//m_shape->draw(_renderer);
}

void Player::PlayerAttackCollision::collision_Enter(HitInformation & _hit)
{
	if (_hit.m_tag != Collision_Tag::ENEMY)return;
	m_player->m_Gauge->up(10);
	m_player->m_timer.initialize();
	m_player->m_isLockOn = true;
	Actor* act = _hit.m_parent;
	AttackStatus attack = m_player->m_combo.getStatus();
	GSvector3 direction = m_player->m_transform.rotate_vector(attack.m_blowOff);
	attack.m_blowOff *= direction;
	act->damage(attack);
	
	if (m_player->m_specialskill.isStart(SPECIALSKILL_TYPE::RECOVERY))
	{
		m_player->m_status.add();
	}
}
