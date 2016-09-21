#include "../../header/airstate/RestrictionFall.h"
#include "../../header/airstate/GroundState.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/math/Calculate.h"

const float RestrictionFall::Restriction = 0.0f;

RestrictionFall::RestrictionFall()
{
}
RestrictionFall::~RestrictionFall()
{
}
void RestrictionFall::start(JumpControl * _control, Player* _player)
{
	_control->setPower(Restriction);
}
void RestrictionFall::airAction(JumpControl * _control, Player* _player, float deltaTime)
{
	_player->movement(deltaTime);
	_control->jumping(deltaTime, _player);
	change(_control, _player);
}

void RestrictionFall::change(JumpControl * _control, Player * _player)
{
	if (next(_player) == nullptr)
	{
		return;
	}
	_control->airActionChange(next(_player));
}

AirAction_Ptr RestrictionFall::next(const Player * _player) const
{
	if (_player->isGround())
	{
		return std::make_shared<GroundState>();
	}
	return nullptr;
}
