#include "header\actor\airstate\jumpControl.h"
#include "header\actor\Player\Player.h"
#include "header\math\Calculate.h"


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
}

void jumpControl::update(Player * _player, float deltaTime)
{

	jumping(_player, deltaTime);
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
}
