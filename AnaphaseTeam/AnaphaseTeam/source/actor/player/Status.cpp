#include "../../../header/actor/Player/Status.h"

//
#include "../../../header/subAction/JumpControl.h"
#include "../../../header/math/Calculate.h"
//

const float Status::MOVESPEED = 0.3f;
const float Status::ROTATESPEED = -2.0f;
const float Status::WALKSPEED = 0.1f;
const float Status::JUMPPOWER = 1.0f;

Status::Status()
	:m_jumpower(1.0f)
{
}

Status::~Status()
{
}

const float Status::getMoveSpeed(bool _leftLegFig, bool _rightLegFig)
{
	m_moveSpeed = MOVESPEED;
	if (_leftLegFig) m_moveSpeed *= 10;
	if (_rightLegFig) m_moveSpeed *= 10;
	return m_moveSpeed;
}

const float Status::getRotateSpeed()
{
	m_rotateSpeed = ROTATESPEED;
	return m_rotateSpeed;
}

const float Status::getWalkSpeed()
{
	m_walkSpeed = WALKSPEED;
	return m_walkSpeed;
}

const float Status::getJumpPower(float _jumpPower)
{
	m_jumpPower = JUMPPOWER;
	m_jumpPower *= _jumpPower;
	return m_jumpPower;
}

const int Status::getHp()
{
	m_hp = 100;
	return m_hp;
}

//
void Status::powerUp()
{
	Math::Clamp clamp;
	m_jumpower = clamp(m_jumpower + 0.2f, 1.0f, 1.4f);
}
void Status::giveJumpPower(JumpControl * _control, float _scale)
{
	_control->setPower(m_jumpower*_scale);
}
//