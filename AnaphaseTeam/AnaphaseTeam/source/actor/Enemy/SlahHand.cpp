#include "../../../header/actor/Enemy/SlahHand.h"
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