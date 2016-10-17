#include "header\airstate\PreparationState.h"
#include "header\"

PreparationState::PreparationState()
{
}

PreparationState::~PreparationState()
{
}

void PreparationState::start(JumpControl * _control)
{
	
}

void PreparationState::airAction(JumpControl * _control, Player * _player, float deltaTime)
{
	_control->airActionChange()
}
