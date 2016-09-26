#include "../../header/airstate/RestrictionFall.h"
#include "../../header/airstate/GroundState.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/math/Calculate.h"
#include "../../header/subAction/JumpControl.h"
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
	_player->moving(deltaTime);
	_control->jumping(deltaTime, _player);
	change(_control, _player);
}

void RestrictionFall::change(JumpControl * _control, Player * _player)
{
	if (_player->isGround())
	{
		_control->airActionChange(std::make_shared<GroundState>());
	}
}
