#include "../../../header/actor/Enemy/Enemy.h"
#include "../../../header/renderer/IRenderer.h"
#include "../../../header/collision/EnemyCollision.h"
#include "../../../header/math/Random.h"
#include "../../../header/math/Calculate.h"
#include "../../../header/actor/Player/Player.h"
#include "../../../header/data/id/ENEMY_ANIMATION.h"
#include "../../../header/collision/EnemyAttackCollision.h"
#include "../../../header/state/enemy/EAttackState.h"
#include "../../../header/state/enemy/EDamageState.h"
#include "../../../header/state/enemy/EDeadState.h"
#include "../../../header/state/enemy/EMoveState.h"
#include "../../../header/state/enemy/ESlideState.h"
#include "../../../header/state/enemy/ESpawnState.h"
#include "../../../header/state/enemy/EStandState.h"
const float Enemy::PLAYER_DISTANCE = 10;
Enemy::Enemy(const Transform & _transform)
	:Actor(_transform, MODEL_ID::ENEMY,
		Actor_Tag::ENEMY),
	m_stay_timer(2),
	m_status(),
	m_alpha(1)
{
}
Enemy::~Enemy()
{
}
void Enemy::initialize()
{
	createStates();
	changeState(ACTOR_STATE::ESPAWN);
	Actor::initialize();
	Collision_Ptr actor = std::make_shared<EnemyCollision>(this);
	m_collision.add(actor);
	m_animatorOne.changeAnimation(ENEMY_ANIMATION::SPAWN, true, false);
	//m_state = ESTATE::SPAWN;
	m_stay_timer.initialize();
	m_status.initialize();
	m_alpha = 1;
}
void Enemy::update(float deltatime)
{
	m_animatorOne.update(deltatime);
	action(deltatime);
	m_collision.update(deltatime);
}

void Enemy::draw(IRenderer * _renderer)
{
	m_collision.draw(_renderer);
	m_animatorOne.draw(_renderer, m_transform, GScolor(1, 1, 1, m_alpha));
}

void Enemy::damage(const AttackStatus & _attackStatus)
{
	if (isDamageState())return;
	//m_state = ESTATE::DAMAGE;
	changeState(ACTOR_STATE::EDAMAGE);
	m_animatorOne.changeAnimation(static_cast<GSuint>(ENEMY_ANIMATION::DAMAGE), true, false, false, 10.0f, 1.5f);
	m_transform.translate_front(_attackStatus.m_blowOff.x);//nockback
	m_status.down(_attackStatus.m_power);
}
void Enemy::damage(Player * _player)
{
	//if (isDamageState())return;
	//m_state = ESTATE::DAMAGE;
	//m_animatorOne.changeAnimation(static_cast<GSuint>(ENEMY_ANIMATION::DAMAGE),true,false,false,10.0f,1.5f);
	//m_transform.translate_front(_player->m_combo.getStatus().m_blowOff.x);//nockback
	//m_hp -= _player->.m_power;
	//_player->gaugeAdd();
}

const bool Enemy::isNear(float _distance) const
{
	return _distance < PLAYER_DISTANCE;
}

void Enemy::state(float deltaTime)
{
	//switch (m_state)
	//{
	//case ESTATE::SPAWN:
	//	if (m_animatorOne.isEndCurrentAnimation())
	//	{
	//		m_state = ESTATE::STAND;
	//	}
	//	break;
	//case ESTATE::STAND:
	//	m_animatorOne.changeAnimation(static_cast<GSuint>(ENEMY_ANIMATION::STAND), true, true);
	//	m_stay_timer.update(deltaTime);
	//	break;
	//case ESTATE::MOVE:
	//	m_animatorOne.changeAnimation(static_cast<unsigned int>(ENEMY_ANIMATION::RUN), true, true);
	//	break;
	//case ESTATE::SLIDE:
	//	m_animatorOne.changeAnimation(static_cast<unsigned int>(ENEMY_ANIMATION::SLIDE), true, true);
	//	break;
	//case ESTATE::ATTACK:
	//	//m_animatorOne.changeAnimation(static_cast<unsigned int>(ENEMY_ANIMATION::ATTACK), true, false, false, 0);
	//	if (m_animatorOne.isEndCurrentAnimation())
	//	{
	//		m_state = ESTATE::STAND;
	//	}
	//	break;
	//case ESTATE::DAMAGE:
	//	if (m_animatorOne.isEndCurrentAnimation())
	//	{
	//		m_state = ESTATE::STAND;
	//	}
	//	break;
	//case ESTATE::DEAD:
	//	m_animatorOne.changeAnimation(static_cast<GSuint>(ENEMY_ANIMATION::DEAD));
	//	m_alpha -= 1 / m_animatorOne.getCurrentAnimationEndTime();
	//	m_isDead = m_animatorOne.isEndCurrentAnimation();
	//	break;
	//}
}

const bool Enemy::isDamageState() const
{
	//return m_state == ESTATE::SPAWN || m_state == ESTATE::ATTACK || m_state == ESTATE::DEAD;
	return getState() == ACTOR_STATE::ESPAWN || getState() == ACTOR_STATE::EATTACK || getState() == ACTOR_STATE::EDEAD;
}

void Enemy::createStates()
{
	registerState(ACTOR_STATE::EATTACK, new EAttackState(this));
	registerState(ACTOR_STATE::EDAMAGE, new EDamageState(this));
	registerState(ACTOR_STATE::ESTAND, new EStandState(this));
	registerState(ACTOR_STATE::EDEAD, new EDeadState(this));
	registerState(ACTOR_STATE::EMOVE, new EMoveState(this));
	registerState(ACTOR_STATE::ESLIDE, new ESlideState(this));
	registerState(ACTOR_STATE::ESPAWN, new ESpawnState(this));
}

void Enemy::slide(Actor * _actor)
{
	m_transform.translate_left(0.03f);
	m_transform.m_rotate = targetDirection(*_actor);
	Math::Clamp clamp;
	m_transform.m_translate = clamp(m_transform.m_translate, GSvector3(-20.0f, -10, -20.0f), GSvector3(20.0f, 10, 20.0f));
}

void Enemy::move(Actor * _actor)
{
	m_transform.translate_up(0.05f);
	m_transform.m_rotate = targetDirection(*_actor);
	Math::Clamp clamp;
	m_transform.m_translate = clamp(m_transform.m_translate, GSvector3(-20.0f, -10, -20.0f), GSvector3(20.0f, 10, 20.0f));
}

void Enemy::attack_start()
{
	m_animatorOne.changeAnimation(static_cast<unsigned int>(ENEMY_ANIMATION::ATTACK), true, false, false, 1.0f);
	float end = m_animatorOne.getCurrentAnimationEndTime() / 60.0f;
	Collision_Ptr actor = std::make_shared<EnemyAttackCollision>(m_transform.m_translate + m_transform.front(), end);
	m_collision.add(actor);
	//m_state = ESTATE::ATTACK;
	changeState(ACTOR_STATE::EATTACK);
}

void Enemy::stay_start()
{
	Math::Random rnd;
	//m_state = ESTATE::STAND;
	changeState(ACTOR_STATE::ESTAND);
	m_stay_timer.setEndTime(rnd(1.0f, 4.0f));
	m_stay_timer.initialize();
}

void Enemy::look_at(CameraController* _camera, Player* _player)
{
	GSvector3 target = m_transform.m_translate;
	_player->look_at(_camera, &target);
}

void Enemy::specialDamage()
{
	m_status.down(m_status.getHp());
}

void Enemy::think(Player * _player)
{
	//if (m_state == ESTATE::DEAD || m_state == ESTATE::DAMAGE || m_state == ESTATE::ATTACK || m_state == ESTATE::SPAWN)return;
	if (getState() == ACTOR_STATE::EDEAD || getState() == ACTOR_STATE::EDAMAGE || getState() == ACTOR_STATE::EATTACK || getState() == ACTOR_STATE::ESPAWN) return;
	if (!m_stay_timer.isEnd())return;
	Math::Random rnd;
	if (rnd(0, 200) == 0)
	{
		stay_start();
		return;
	}
	if (rnd(0, 200) == 0)
	{
		attack_start();
		return;
	}
	float distance = distanceActor(*_player);
	if (isNear(distance))
	{
		//m_state = ESTATE::SLIDE;
		changeState(ACTOR_STATE::ESLIDE);
		slide(_player);
		return;
	}
	move(_player);
	//m_state = ESTATE::MOVE;
	changeState(ACTOR_STATE::EMOVE);
}
