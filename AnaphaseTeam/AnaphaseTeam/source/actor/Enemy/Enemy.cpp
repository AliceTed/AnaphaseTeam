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
#include "../../../header/state/enemy/EDashFrontState.h"
#include "../../../header/state/enemy/EMoveBackState.h"
#include "../../../header/state/enemy/EThinkState.h"
#include "../../../header/state/enemy/ESecoundAttackState.h"
#include "../../../header/ui/HPGaugeUI.h"
#include "../../../header/ui/UIManager.h"
#include "../../../header/state/enemy/NearAI.h"
#include "../../../header/state/enemy/OverNearAI.h"
#include "../../../header/state/enemy/MiddleRangeAI.h"
#include "../../../header/state/enemy/OverFarAI.h"
#include "../../../header/state/enemy/EAI.h"
#include "../../../header/actor/Enemy/EnemyMediator.h"
const float Enemy::PLAYER_DISTANCE_NEAR = 2.0f;
const float Enemy::PLAYER_DISTANCE_MID = 3.0f;
const float Enemy::PLAYER_DISTANCE_FAR = 7.5f;
Enemy::Enemy(const Transform & _transform,EnemyMediator& _mediator)
	:Actor(_transform, MODEL_ID::ENEMY,
		Actor_Tag::ENEMY),
	m_status(),
	m_alpha(1),
	m_knockBack(m_transform),
	m_AI(),m_mediator(_mediator),

	m_gravity(0.0f)
{
}
Enemy::~Enemy()
{
}
void Enemy::initialize()
{
	Actor::initialize();
	createStates();
	changeState(ACTOR_STATE::ESPAWN);
	Collision_Ptr actor = std::make_shared<EnemyCollision>(this);
	m_collision.add(actor);
	m_AI.initialize();
	m_AI.add(EAI::ATTACKRANGE, std::shared_ptr<NearAI>(new NearAI(this)));
	m_AI.add(EAI::OVERNEAR, std::shared_ptr<OverNearAI>(new OverNearAI(this)));
	m_AI.add(EAI::MIDDRANGE, std::shared_ptr<MiddleRangeAI>(new MiddleRangeAI(this)));
	m_AI.add(EAI::OVERFAR, std::shared_ptr<OverFarAI>(new OverFarAI(this)));
	m_AI.change(EAI::ATTACKRANGE);
	m_animatorOne.changeAnimationLerp(ENEMY_ANIMATION::STANDDYNIG);
	m_status.initialize();
	m_alpha = 1;

	m_gravity = 0.0f;
}
void Enemy::update(float deltatime)
{
	m_animatorOne.update(deltatime);
	action(deltatime);
	m_collision.update(deltatime);
	if (!m_isGround)
	{
		m_gravity -= 0.004f;
		changeGravity(m_gravity);
		return;
	}
	m_gravity = 0.0f;
	changeGravity(-0.05f);
}

void Enemy::draw(IRenderer * _renderer)
{
	m_collision.draw(_renderer);
	m_animatorOne.draw(_renderer, m_transform, GScolor(1, 1, 1, m_alpha));
}

void Enemy::damage(const AttackStatus & _attackStatus)
{
	if (isNotDamageState())return;
	changeState(ACTOR_STATE::EDAMAGE);
	//m_animatorOne.changeAnimation(static_cast<GSuint>(ENEMY_ANIMATION::DAMAGE), true, false, false, 10.0f, 1.5f);
	m_status.down(_attackStatus.m_power);
	if (!m_isGround)
	{
		m_knockBack.start(GSvector3(0, 0.3f, 0));
		return;
	}
	m_animatorOne.changeAnimationLerp(ENEMY_ANIMATION::DAMAGE1, 1.5f);
	m_knockBack.start(_attackStatus.m_blowOff);
	
}
const EAI Enemy::isNear(float _distance) const
{
	EAI ai=EAI::ATTACKRANGE;
	//ãﬂÇ∑Ç¨
	if (_distance <= PLAYER_DISTANCE_NEAR)ai = EAI::OVERNEAR;
	//çUåÇîÕàÕ
	if(_distance>PLAYER_DISTANCE_NEAR&&_distance<=PLAYER_DISTANCE_MID)
		ai = EAI::ATTACKRANGE;
	//íÜä‘
	if (_distance>PLAYER_DISTANCE_MID&&_distance<=PLAYER_DISTANCE_FAR)
		ai = EAI::MIDDRANGE;
	//âìÇ∑Ç¨
	if (_distance > PLAYER_DISTANCE_FAR)
		ai = EAI::OVERFAR;

	return ai;
}
const bool Enemy::blowDead()const
{
	return	m_knockBack.isBlow();
}

const bool Enemy::isThink() const
{
	return getState() == ACTOR_STATE::ETHINK;// || getState() == ACTOR_STATE::EMOVE || getState() == ACTOR_STATE::EDASH || getState() == ACTOR_STATE::EMOVEBACK;
}
const bool Enemy::isNotDamageState() const
{
	//ÉXÉ|Å[ÉìÇ∆éÄñSíÜÇÕêHÇÁÇÌÇ»Ç¢
	return getState() == ACTOR_STATE::ESPAWN || getState() == ACTOR_STATE::EDEAD;
}

const bool Enemy::isDeadState() const
{
	return getState() == ACTOR_STATE::EDEAD;
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
	registerState(ACTOR_STATE::EDASH, new EDashFrontState(this));
	registerState(ACTOR_STATE::EMOVEBACK, new EMoveBackState(this));
	registerState(ACTOR_STATE::ETHINK, new EThinkState(this));
	registerState(ACTOR_STATE::ESECOUNDATTACK, new ESecoundAttackState(this));
}

void Enemy::createAttackCollision()
{
	float end = m_animatorOne.getCurrentAnimationEndTime() / 60.0f;
	Collision_Ptr actor = std::make_shared<EnemyAttackCollision>(m_transform.m_translate + m_transform.front(), end);
	m_collision.add(actor);
}

void Enemy::look_at(CameraController* _camera, Player* _player)
{
	GSvector3 target = m_transform.m_translate;
	_player->look_at(_camera, &target);
}

void Enemy::specialDamage()
{
	m_status.down(m_status.getHp());
	changeState(ACTOR_STATE::EDAMAGE);
}

void Enemy::think(Player * _player)
{
	m_transform.m_rotate = targetDirection(*_player);
	float distance = distanceActor(*_player);
	if (!isThink())return;
	m_AI.change(isNear(distance));
	m_AI.think(_player);
}

void Enemy::start_lockOn()
{
	UIManager::getInstance().release(EUI::ENEMYHP);
	std::shared_ptr<HPGaugeUI> hp = std::make_shared<HPGaugeUI>(GSvector2(800, 600), m_status, 3.0f);
	UIManager::getInstance().add(EUI::ENEMYHP, hp);
}
float Enemy::distaceToPlayer()
{
	return m_mediator.requestDistancePlayer(this);
}
float Enemy::distaceToOtherEnemy()
	{
	return m_mediator.requestDistanceOtherEnemy(this);
	}

EAI Enemy::currentDistance()
{
	return m_AI.currentDistanceJudg();
}

bool Enemy::requestDistance(EAI _distance)
{
	if (_distance == EAI::ATTACKRANGE)
		return m_mediator.reqestGoToNear();
	if (_distance == EAI::MIDDRANGE)
		return m_mediator.reqestGoToMid();

	return false;
}