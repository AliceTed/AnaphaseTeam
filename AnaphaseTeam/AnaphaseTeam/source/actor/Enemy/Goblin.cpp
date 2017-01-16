#include "../../../header/actor/Enemy/Goblin.h"
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
#include "../../../header/state/enemy/NearAI.h"
#include "../../../header/state/enemy/OverNearAI.h"
#include "../../../header/state/enemy/MiddleRangeAI.h"
#include "../../../header/state/enemy/OverFarAI.h"
#include "../../../header/state/enemy/EAI.h"
#include "../../../header/actor/Enemy/EnemyMediator.h"

#include "../../../header/renderer/define/SpriteRenderDesc.h"
#include "../../../header/renderer/define/ViewportDesc.h"
#include <math.h>
Goblin::Goblin(const Transform & _transform, EnemyMediator& _mediator)
	:IEnemy(_transform, MODEL_ID::ENEMY, _mediator)
{
}
Goblin::~Goblin()
{
}
void Goblin::initialize()
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
void Goblin::update(float deltatime)
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
	m_timer.update(deltatime);

	rotateLerp(&m_transform.m_rotate, m_timer.time / m_timer.maxTime);
}

void Goblin::draw(IRenderer * _renderer)
{
	m_collision.draw(_renderer);
	m_animatorOne.draw(_renderer, m_transform, GScolor(1, 1, 1, m_alpha));
}

void Goblin::damage(const AttackStatus & _attackStatus)
{
	if (isNotDamageState())return;
	changeState(ACTOR_STATE::EDAMAGE);
	m_status.down(_attackStatus.m_power);
	if (!m_isGround)
	{
		m_knockBack.start(GSvector3(0, 0.3f, 0));
		return;
	}
	m_animatorOne.changeAnimationLerp(ENEMY_ANIMATION::DAMAGE1, 1.5f);
	m_knockBack.start(_attackStatus.m_blowOff);
}
void Goblin::createStates()
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

void Goblin::think(Player * _player)
{
	float distance = distanceActor(*_player);
	m_debug = targetDirection(*_player);
	if (!isThink())return;
	m_AI.change(isNear(distance));
	//m_AI.think(_player);
}
