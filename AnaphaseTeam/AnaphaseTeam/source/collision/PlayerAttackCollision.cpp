#include "..\..\header\collision\PlayerAttackCollision.h"
#include "../../header/shape/Sphere.h"
#include "../../header/collision/HitInformation.h"
#include  "../../header/attack/ShapeData.h"
#include "../../header/device/GameDevice.h"
#include "../../header/data/id/SE_ID.h"
#include "renderer\IRenderer.h"
#include "effect\effectmanager.h"
Player::PlayerAttackCollision::PlayerAttackCollision(Player* _player, const ShapeData& _data,float _speed)
	:CollisionActor(_data.shape,Collision_Tag::PLAYER_WEAPON),
	m_player(_player),
	m_destroy(_data.destroyTime),
	m_offset(_data.offset),
	m_speed(_speed)
{
}

void Player::PlayerAttackCollision::doUpdate(float deltaTime)
{
	Transform t = Transform({ 0,0,0 }, m_offset);
	t=t.parent_synthesis(m_player->m_transform);
	p = t.m_translate;
	m_shape->transfer(t.m_translate);
	float speed = m_player->m_status.attackSpeed() * m_speed;
	m_destroy.update(deltaTime*speed);
	if (m_destroy.isEnd() || m_player->getState() == ACTOR_STATE::STEP)
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
	m_player->m_Gauge->up(2);
	m_player->m_timer.initialize();
	m_player->m_isLockOn = true;
	Actor* act = _hit.m_parent;
	AttackStatus attack = m_player->m_combo.getStatus();
	GSvector3 direction = m_player->m_transform.rotate_vector(attack.m_blowOff);
	attack.m_blowOff = direction;
	act->damage(attack);
	EffectManager::getInstance().effectPlay(EFFECT_ID::PLAYER_ATTACK,p);
	GameDevice::getInstacnce().sound().playSE(SE_ID::ENEMY_DAMAGE);

	if (m_player->m_combo.isFinishAttack())
	{
		Sleep(150);
	}
}
