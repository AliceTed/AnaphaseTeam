/**
* @file IEnemy.cpp
* @brief ボスクラス
* @author 久秋
* @date 2017/01/16
ボスの特徴・仕様
ゴブリンより大きい
耐久力も多い
耐久力が一定以下になるとモデルを変えて、行動パターンも変わる
*/
#include "actor/Boss/Boss.h"
#include "actor/Player/Player.h"
#include "data/id/ENEMY_ANIMATION.h"
#include "collision/EnemyAttackCollision.h"
#include "actor\Boss\BossAI.h"
#include "state\boss\BStandState.h"
#include"data\stream\EStatusReader.h"
#include "collision\EnemyCollision.h"
Boss::Boss(const Transform & _transform, EnemyMediator & _mediator)
	:IEnemy(_transform, MODEL_ID::BOSS, _mediator,Actor_Tag::BOSS)
{
}

Boss::~Boss()
{
}

void Boss::initialize()
{
	Actor::initialize();
	readStatus();
	Collision_Ptr actor = std::make_shared<EnemyCollision>(this);
	m_collision.add(actor);
	createStates();
	changeState(ACTOR_STATE::BSTAND);
	m_AI.initialize();
	m_AI.add(EAI::ATTACKRANGE, std::shared_ptr<BossAI>(new BossAI(this)));
	m_AI.change(EAI::ATTACKRANGE);
	m_status.initialize();	
	m_alpha = 1;
	m_isDown = false;
}

void Boss::update(float deltatime)
{
	lookAtToPlayer();
	m_animatorOne.update(deltatime);
	action(deltatime);
	m_collision.update(deltatime);
	m_rotateTimer.update(deltatime);
	rotateLerp(&m_transform.m_rotate, m_rotateTimer.time / m_rotateTimer.maxTime);

}

void Boss::draw(IRenderer * _renderer)
{
	m_collision.draw(_renderer);
	m_animatorOne.draw(_renderer, m_transform, GScolor(1, 1, 1, m_alpha));
}

void Boss::damage(const AttackStatus & _attackStatus)
{
	m_status.down(_attackStatus.m_power);
}

void Boss::think(Player * _player)
{
	if (!isThink())return;
	m_AI.think(_player);
}

void Boss::createStates()
{
	registerState(ACTOR_STATE::BSTAND, new BStandState(this));
}

void Boss::blowDamageDecision(const GSvector3 & _blowPower)
{
}

void Boss::readStatus()
{
	EStatusReader reader;
	reader(&m_status, &m_attackStatus, m_gravityAcc, "estatus");
}
