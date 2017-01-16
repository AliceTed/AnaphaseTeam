#include "../../../header/actor/Enemy/IEnemy.h"
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
#include "../../../header/ui/HPGaugeUI.h"
#include "../../../header/ui/UIManager.h"
#include "../../../header/state/enemy/NearAI.h"
#include "../../../header/state/enemy/OverNearAI.h"
#include "../../../header/state/enemy/MiddleRangeAI.h"
#include "../../../header/state/enemy/OverFarAI.h"
#include "../../../header/state/enemy/EAI.h"
#include "../../../header/actor/Enemy/EnemyMediator.h"
#include "math\Calculate.h"



const float IEnemy::PLAYER_DISTANCE_NEAR = 2.0f;
const float IEnemy::PLAYER_DISTANCE_MID = 3.0f;
const float IEnemy::PLAYER_DISTANCE_FAR = 7.5f;
IEnemy::IEnemy(const Transform& _transform, MODEL_ID _modelID, EnemyMediator& _mediator)
	:
	Actor(_transform, _modelID, Actor_Tag::ENEMY),
	m_status(),
	m_alpha(1),
	m_knockBack(m_transform),
	m_AI(), m_mediator(_mediator),
	m_gravity(0.0f)
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
	//m_transform.m_rotate.dot(m_mediator.requestPlayerDirection(this));
	if (50.0f < fabsf(m_transform.m_rotate.getYaw() - m_mediator.requestPlayerDirection(this).getYaw()))
	{
			lookAtToPlayer();
	}
}
void IEnemy::lookAtToPlayer()
{
	/*ラープタイマー開始*/
	m_timer.begin();
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
	if (_distance == EAI::ATTACKRANGE)
		return m_mediator.reqestGoToNear();
	if (_distance == EAI::MIDDRANGE)
		return m_mediator.reqestGoToMid();

	return false;
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
	Collision_Ptr actor = std::make_shared<EnemyAttackCollision>(m_transform.m_translate + m_transform.front(), end);
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