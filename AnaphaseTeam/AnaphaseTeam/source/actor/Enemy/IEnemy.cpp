/**
* @file IEnemy.cpp
* @brief 敵の仮想クラス
* @author 久秋
* @date 2016/12/15
*/
#include "actor/Enemy/IEnemy.h"
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
#include "ui/HPGaugeUI.h"
#include "ui/UIManager.h"
#include "state/enemy/NearAI.h"
#include "state/enemy/OverNearAI.h"
#include "state/enemy/MiddleRangeAI.h"
#include "state/enemy/OverFarAI.h"
#include "state/enemy/EAI.h"
#include "actor/Enemy/EnemyMediator.h"
#include "math\Calculate.h"

const float IEnemy::PLAYER_DISTANCE_NEAR = 2.0f;
const float IEnemy::PLAYER_DISTANCE_MID = 3.0f;
const float IEnemy::PLAYER_DISTANCE_FAR = 7.5f;
IEnemy::IEnemy(const Transform& _transform, MODEL_ID _modelID, EnemyMediator& _mediator,Actor_Tag _tag)
	:
	Actor(_transform, _modelID,_tag),
	m_status(),
	m_alpha(1),
	m_knockBack(m_transform),
	m_AI(), m_mediator(_mediator)
{

}

void IEnemy::look_at(CameraController* _camera, Player* _player)
{
	GSvector3 target = m_transform.m_translate;
	_player->look_at(_camera, &target);
	_player->targetMaker(target);
	
}

void IEnemy::specialDamage()
{

	m_status.down(m_status.getHp());
	changeState(ACTOR_STATE::EDAMAGE);
}

void IEnemy::start_lockOn()
{
	UIManager::getInstance().release(EUI::ENEMYHP);
	std::shared_ptr<HPGaugeUI> hp = std::make_shared<HPGaugeUI>(GSvector2(800, 600), m_status);
	UIManager::getInstance().add(EUI::ENEMYHP, hp);


}

void IEnemy::end_lockOn()
{
	UIManager::getInstance().release(EUI::ENEMYHP);
}

float IEnemy::distaceToPlayer()
{
	return m_mediator.requestDistancePlayer(this);
}
float IEnemy::distaceToOtherEnemy()
{
	return m_mediator.requestDistanceOtherEnemy(this);
}
void IEnemy::directionToPlayer()
{
	if (50.0f < fabsf(m_transform.m_rotate.getYaw() - m_mediator.requestPlayerDirection(this).getYaw()))
	{
			lookAtToPlayer();
	}
}
void IEnemy::lookAtToPlayer()
{
	/*ラープタイマー開始*/
	m_rotateTimer.begin();
	/*targetをプレイヤーがいる方向へ入れ替え*/
	m_targetDirection = m_mediator.requestPlayerDirection(this);
}

void IEnemy::scoreDamage()
{
	m_mediator.addScore(1);
}

void IEnemy::scoreDead()
{
	m_mediator.addScore(5);
}

EAI IEnemy::currentAIRange()
{
	return m_AI.currentRange();
}
bool IEnemy::requestDistance(EAI _distance)
{
	return m_mediator.isExist(_distance);
}

const bool IEnemy::isNotDamageState()const
{
	//スポーンと死亡中は食らわない
	return getState() == ACTOR_STATE::ESPAWN || getState() == ACTOR_STATE::EDEAD;
}
const bool IEnemy::isDeadState() const
{
	return getState() == ACTOR_STATE::EDEAD;
}
const bool IEnemy::isThink()const
{
	return getState() == ACTOR_STATE::ETHINK;
}

const EAI IEnemy::dicisionOfAI(float _distance)const
{
	Math::Range range;
	EAI ai = EAI::ATTACKRANGE;
	//近すぎ
	if (_distance < PLAYER_DISTANCE_NEAR)
		ai = EAI::OVERNEAR;
	//攻撃範囲
	if (range(_distance , PLAYER_DISTANCE_NEAR, PLAYER_DISTANCE_MID))
		ai = EAI::ATTACKRANGE;
	//中間
	if (range(_distance, PLAYER_DISTANCE_MID, PLAYER_DISTANCE_FAR))
		ai = EAI::MIDDRANGE;
	//遠すぎ
	if (PLAYER_DISTANCE_FAR < _distance)
		ai = EAI::OVERFAR;

	return ai;
}
const bool IEnemy::blowDead()const
{
	return	m_knockBack.isBlow();
}

void IEnemy::createAttackCollision()
{
	float end = m_animatorOne.getCurrentAnimationEndTime() / 60.0f;
	Collision_Ptr actor = std::make_shared<EnemyAttackCollision>(this, m_transform.m_translate + m_transform.front(), end);
	m_collision.add(actor);
}

void IEnemy::rotateLerp(GSquaternion* _out, float _time)
{
	/*
	プレイヤーが左右どちらにいるか確認して
	回転方向を決める
	*/
	if (0.0f < gsQuaternionDot(_out, &m_targetDirection))
	{
		gsQuaternionLerp(_out, _out, &m_targetDirection, _time);
		return;
	}
	gsQuaternionLerp(_out, &m_targetDirection, _out, _time);
}