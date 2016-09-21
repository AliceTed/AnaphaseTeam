#include "../../header/airstate/RestrictionFall.h"

RestrictionFall::RestrictionFall()
{
}
RestrictionFall::~RestrictionFall()
{
}
void RestrictionFall::start(JumpControl * _control)
{
	_control->start(0);
}
void RestrictionFall::airAction(JumpControl * _control, Player* _player, float deltaTime)
{
	_control->jumping(_player, deltaTime);
}
void RestrictionFall::next(JumpControl * _control)
{
}