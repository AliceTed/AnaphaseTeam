#include "header\actor\airstate\jumpControl.h"
#include "header\actor\Player\Player.h"
#include "header\math\Calculate.h"
#include "header\actor\airstate\firstStep.h"
#include "secondStep.h"
#include "groundState.h"

#include <string>

const float jumpControl::MaxJumpPower = 2.0f;

jumpControl::jumpControl()
	:m_State(JUMPSTATE::Non)
{

}

jumpControl::~jumpControl()
{

}

void jumpControl::initialize()
{
	airActionChange(std::make_shared<groundState>());
}

const bool jumpControl::isGround() const
{
	return m_State == JUMPSTATE::Non;
}

void jumpControl::groundHit()
{
	m_State = JUMPSTATE::Non;
}

void jumpControl::jumping(Player * _player, float deltaTime)
{

	if (m_State == JUMPSTATE::Non)return;

	_player->jumping(m_JumpPower*deltaTime);
	Math::Clamp clamp;
	m_JumpPower = clamp(m_JumpPower - m_Acceleration, -MaxJumpPower, MaxJumpPower);
}

void jumpControl::start(const float _jumpStepPow)
{
	if (m_State == JUMPSTATE::SecondStep)return;

	m_JumpPower = _jumpStepPow;

	m_State = isGround() ? JUMPSTATE::FristStep : JUMPSTATE::SecondStep;	
}

void jumpControl::airActionChange(AirAction_Ptr _airAction)
{
	m_airAction = _airAction;
	m_airAction->airAction(this);
}

void jumpControl::draw()
{
	glColor4f(1, 1, 1, 1);
	gsTextPos(300, 100);
	gsDrawText(std::to_string(m_JumpPower).c_str());
}