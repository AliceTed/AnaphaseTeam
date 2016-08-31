/**
* @file jumpControl.cpp
* @brief ƒWƒƒƒ“ƒv‚Ì§Œä
* @author a’J’m÷
* @date 2016/08/29
*/
#include "../../../header/actor/airstate/jumpControl.h"
#include "../../../header/actor/Player/Player.h"
#include "../../../header/math/Calculate.h"
//#include "../../../header/actor/airstate/firstStep.h"
//#include "../../../header/actor/airstate/secondStep.h"
#include "../../../header/actor/airstate/groundState.h"
#include "../../../header/actor/airstate/RigorStateh.h"

#include <string>

const float jumpControl::MaxJumpPower = 2.0f;

jumpControl::jumpControl()
	:m_Acceleration(0.1f),
	m_airAction(std::make_shared<groundState>())
{

}

jumpControl::~jumpControl()
{

}

//const bool jumpControl::isGround() const
//{
//	return m_State == JUMPSTATE::Non;
//}

void jumpControl::update(Player* _player, float deltaTime)
{
	m_airAction->airAction(this, _player, deltaTime);
}

void jumpControl::groundHit()
{
	//m_State = JUMPSTATE::Non;
	airActionChange(std::make_shared<RigorState>());
}

void jumpControl::jumping(Player * _player, float deltaTime)
{
	//if (m_State == JUMPSTATE::Non)return;

	_player->jumping(m_JumpPower*deltaTime);
	Math::Clamp clamp;
	m_JumpPower = clamp(m_JumpPower - m_Acceleration, -MaxJumpPower, MaxJumpPower);
}

void jumpControl::start(const float _jumpStepPow)
{
	//if (m_State == JUMPSTATE::SecondStep)return;

	m_JumpPower = _jumpStepPow;

	//m_State = isGround() ? JUMPSTATE::FristStep : JUMPSTATE::SecondStep;	
}

void jumpControl::airActionChange(AirAction_Ptr _airAction)
{
	m_airAction = _airAction;
	m_airAction->start(this);
	//m_airAction->airAction(this);
}

void jumpControl::jump()
{
	m_airAction->next(this);
}