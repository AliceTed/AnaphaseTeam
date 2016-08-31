#include "../../../header/actor/airstate/RestrictionFall.h"

RestrictionFall::RestrictionFall()
{
}

RestrictionFall::~RestrictionFall()
{
}

void RestrictionFall::start(jumpControl * _jumpAction)
{
	_jumpAction->start(0);
}

void RestrictionFall::airAction(jumpControl * _jumpAction, Player* _player, float deltaTime)
{
	_jumpAction->jumping(_player, deltaTime);
}

void RestrictionFall::next(jumpControl * _control)
{
}
