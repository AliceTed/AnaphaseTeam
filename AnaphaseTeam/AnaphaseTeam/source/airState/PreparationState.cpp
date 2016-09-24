#include "../../header/airstate/PreparationState.h"
#include "../../header/airstate/FirstStep.h"
#include "../../header/subaction/JumpControl.h"
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
	AirAction_Ptr next = std::make_shared<FirstStep>();
	_control->airActionChange(next);
}
