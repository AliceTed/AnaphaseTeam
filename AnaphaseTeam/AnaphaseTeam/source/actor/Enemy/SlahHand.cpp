#include "actor/Enemy/SlahHand.h"
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

SlahHand::SlahHand(const Transform& _transform, EnemyMediator& _mediator)
:IEnemy(_transform,MODEL_ID::ENEMY,_mediator)
{

}
SlahHand::~SlahHand()
{
}
void SlahHand::initialize()
{

}
void SlahHand::update(float deltatime)
{
}
void SlahHand::draw(IRenderer* _renderer)
{
}
void SlahHand::damage(const AttackStatus& _attackStatus)
{
}


void SlahHand::createStates()
{
}
void SlahHand::think(Player* _palyer)
{

}