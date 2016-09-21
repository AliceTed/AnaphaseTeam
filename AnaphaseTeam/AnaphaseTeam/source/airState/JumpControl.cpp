/**
* @file jumpControl.cpp
* @brief ƒWƒƒƒ“ƒv‚Ì§Œä
* @author a’J’m÷
* @date 2016/08/29
*/
#include "../../header/airstate/jumpControl.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/math/Calculate.h"
#include "../../header/airstate/groundState.h"
#include "../../header/airstate/PreparationState.h"

const float JumpControl::Acceleration = 0.1f;
const float JumpControl::MaxJumpPower = 2.0f;
JumpControl::JumpControl(Player* _player)
	:m_airAction(std::make_shared<PreparationState>()),
	m_player(_player),
	m_isEnd(false)
{

}

JumpControl::~JumpControl()
{

}

void JumpControl::initialize()
{
	m_isEnd = false;
	airActionChange(std::make_shared<PreparationState>());
}

void JumpControl::update(float deltaTime)
{
	m_airAction->airAction(this, m_player, deltaTime);
}

void JumpControl::airActionChange(AirAction_Ptr _airAction)
{
	m_airAction = _airAction;
	m_airAction->start(this, m_player);
}

void JumpControl::end()
{
	m_isEnd = true;
}

const bool JumpControl::isEnd() const
{
	return m_isEnd;
}

void JumpControl::setPower(float _power)
{
	m_JumpPower = _power;
}

void JumpControl::jumping(float deltaTime, Player * _player)
{
	_player->jumping(m_JumpPower*deltaTime);
	Math::Clamp clamp;
	m_JumpPower = clamp(m_JumpPower - Acceleration, -MaxJumpPower, MaxJumpPower);
}
