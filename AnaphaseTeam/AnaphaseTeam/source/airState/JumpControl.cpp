/**
* @file jumpControl.cpp
* @brief �W�����v�̐���
* @author �a�J�m��
* @date 2016/08/29
*/
#include "../../header/airstate/jumpControl.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/math/Calculate.h"
#include "../../header/airstate/groundState.h"
#include "../../header/airstate/RigorState.h"

const float JumpControl::MaxJumpPower = 2.0f;

JumpControl::JumpControl()
	:m_Acceleration(0.1f),
	m_airAction(std::make_shared<GroundState>())
{

}
JumpControl::~JumpControl()
{

}
void JumpControl::update(Player* _player, float deltaTime)
{
	m_airAction->airAction(this, _player, deltaTime);
}
void JumpControl::groundHit()
{
	airActionChange(std::make_shared<RigorState>());
}
void JumpControl::jumping(Player * _player, float deltaTime)
{
	_player->jumping(m_JumpPower*deltaTime);
	Math::Clamp clamp;
	m_JumpPower = clamp(m_JumpPower - m_Acceleration, -MaxJumpPower, MaxJumpPower);
}
void JumpControl::start(const float _jumpStepPow)
{
	m_JumpPower = _jumpStepPow;
}
void JumpControl::airActionChange(AirAction_Ptr _airAction)
{
	m_airAction = _airAction;
	m_airAction->start(this);
}
void JumpControl::jump()
{
	m_airAction->next(this);
}