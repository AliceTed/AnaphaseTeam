#include "../../../header/actor/Boss/Boss.h"

Boss::Boss(const Transform & _transform, EnemyMediator & _mediator)
	:IEnemy(_transform, MODEL_ID::ENEMY, _mediator)
{
}

Boss::~Boss()
{
}

void Boss::initialize()
{
}

void Boss::update(float deltatime)
{
}

void Boss::draw(const IRenderer & _renderer)
{
}

void Boss::damage(const AttackStatus & _attackStatus)
{
}

void Boss::think(Player * _palyer)
{
}

void Boss::createStates()
{
}
