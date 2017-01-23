#include "actor/Enemy/Goblin.h"
#include "renderer/IRenderer.h"
#include "collision/EnemyCollision.h"
#include "math/Random.h"
#include "math/Calculate.h"
#include "actor/Player/Player.h"
#include "data/id/ENEMY_ANIMATION.h"
#include "collision/EnemyAttackCollision.h"
#include "state/enemy/EAttackState.h"
#include "state/enemy/EDamageState.h"
#include "state/enemy/EDeadState.h"
#include "state/enemy/EMoveState.h"
#include "state/enemy/ESlideState.h"
#include "state/enemy/ESpawnState.h"
#include "state/enemy/EStandState.h"
#include "state/enemy/EDashFrontState.h"
#include "state/enemy/EMoveBackState.h"
#include "state/enemy/EThinkState.h"
#include "state/enemy/ESecoundAttackState.h"
#include "state/enemy/NearAI.h"
#include "state/enemy/OverNearAI.h"
#include "state/enemy/MiddleRangeAI.h"
#include "state/enemy/OverFarAI.h"
#include "state/enemy/EAI.h"
#include "actor/Enemy/EnemyMediator.h"
#include "../../../header/data/stream/EStatusReader.h"

#include "renderer/define/SpriteRenderDesc.h"
#include "renderer/define/ViewportDesc.h"
#include <math.h>

static const float BLOW_DAMAGE_POWER = 0.4f;

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
	EStatusReader reader;
	reader(&m_status, &m_attackStatus, m_gravity, "estatus");
	m_AI.initialize();
	m_AI.add(EAI::ATTACKRANGE, std::shared_ptr<NearAI>(new NearAI(this)));
	m_AI.add(EAI::OVERNEAR, std::shared_ptr<OverNearAI>(new OverNearAI(this)));
	m_AI.add(EAI::MIDDRANGE, std::shared_ptr<MiddleRangeAI>(new MiddleRangeAI(this)));
	m_AI.add(EAI::OVERFAR, std::shared_ptr<OverFarAI>(new OverFarAI(this)));
	m_AI.change(EAI::ATTACKRANGE);
	m_animatorOne.changeAnimationLerp(ENEMY_ANIMATION::STANDDYNIG);
	m_status.initialize();
	//m_status.m_hp = 100;
	m_alpha = 1;
	
	//m_gravity = 0.0f;
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
	//m_gravity = 0.0f;
	changeGravity(-0.05f);
	m_rotateTimer.update(deltatime);
	rotateLerp(&m_transform.m_rotate, m_rotateTimer.time / m_rotateTimer.maxTime);
}

void Goblin::draw(IRenderer * _renderer)
{
	m_collision.draw(_renderer);
	m_animatorOne.draw(_renderer, m_transform, GScolor(1, 1, 1, m_alpha));
}

void Goblin::damage(const AttackStatus & _attackStatus)
{
	if (isNotDamageState())return;
	changeState(ACTOR_STATE::EDAMAGE);//�_���[�W�X�e�[�g�ɕύX
	m_status.down(_attackStatus.m_power);//�̗͌���
	if (!m_isGround)//�����Ă�Ԃ͐�����тɂ���
	{
		blowDamageDecision(_attackStatus.m_blowOff);
		m_knockBack.start(GSvector3(0, 0.3f, 0));
		return;
	}
	blowDamageDecision(_attackStatus.m_blowOff);//�A�j���[�V�����ύX
	m_knockBack.start(_attackStatus.m_blowOff);//�m�b�N�o�b�N�l�ݒ�
}
void Goblin::blowDamageDecision(const GSvector3& _blowPower)
{
	//��_���[�W��������ї͂����ȏゾ�ƃA�j���[�V������ς���
	if (_blowPower.length() > BLOW_DAMAGE_POWER)
	{
		//������ԕ�
		m_animatorOne.changeAnimationLerp(ENEMY_ANIMATION::DIE2, 1.5f);
		return;
	}
	//�����̋���
	m_animatorOne.changeAnimationLerp(ENEMY_ANIMATION::DAMAGE1, 1.5f);
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
	if (!isThink())return;
	m_AI.change(dicisionOfAI(distanceActor(*_player)));
	m_AI.think(_player);
}
