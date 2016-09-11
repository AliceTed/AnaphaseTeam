#include "../../header/airstate/RestrictionFall.h"

RestrictionFall::RestrictionFall()
{
}
RestrictionFall::~RestrictionFall()
{
}
void RestrictionFall::start(JumpControl * _jumpAction)
{
	_jumpAction->start(0);
}
void RestrictionFall::airAction(JumpControl * _jumpAction, Player* _player, float deltaTime)
{
	_jumpAction->jumping(_player, deltaTime);
}
void RestrictionFall::next(JumpControl * _control)
{
}