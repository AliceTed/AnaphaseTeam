#include "../../header/airstate/PreparationState.h"
#include "../../header/airstate/FirstStep.h"
#include "../../header/airstate/JumpControl.h"
#include "../../header/actor/Player/Player.h"

PreparationState::PreparationState()
{
}

PreparationState::~PreparationState()
{
}

void PreparationState::start(JumpControl * _control, Player* _player)
{
}

void PreparationState::airAction(JumpControl * _control, Player * _player, float deltaTime)
{
	/*if (_player->isJump())
	{
		AirAction_Ptr next = std::make_shared<FirstStep>();
		_control->airActionChange(next);
	}*/
	AirAction_Ptr next = std::make_shared<FirstStep>();
	_control->airActionChange(next);
}
