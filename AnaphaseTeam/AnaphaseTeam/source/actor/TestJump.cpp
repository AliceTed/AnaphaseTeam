//#include "../../header/actor/TestJump.h"
//#include "../../header/actor/Player/Player.h"
//
//#include "../../header/math/Calculate.h"
//
////const float TestJump::FirstStepPow=1.2f;
////const float TestJump::SecondStepPow=1.0f;
//const float TestJump::MaxJumpPower = 2.0f;
//TestJump::TestJump()
//	:m_JumpPower(0),
//	m_Acceleration(0.1f),
//	m_State(JUMPSTATE::Non)
//{
//}
//
//TestJump::~TestJump()
//{
//}
//
//void TestJump::jumping(Player * _player, float deltaTime)
//{
//	if (m_State == JUMPSTATE::Non)return;
//
//	_player->jumping(m_JumpPower*deltaTime);
//	Math::Clamp clamp;
//	m_JumpPower = clamp(m_JumpPower - m_Acceleration, -MaxJumpPower, MaxJumpPower);
//}
//
//void TestJump::start(const float _jumpStepPow)
//{
//	if (m_State == JUMPSTATE::SecondStep)return;
//
//	/*m_JumpPower = _jumpStepPow;*/
//
//	m_JumpPower = isGround() ? FirstStepPow:SecondStepPow;
//	m_State = isGround() ? JUMPSTATE::FristStep : JUMPSTATE::SecondStep;	
//}
//
//const bool TestJump::isGround() const
//{
//	return m_State==JUMPSTATE::Non;
//}
//
//void TestJump::groundHit()
//{
//	m_State = JUMPSTATE::Non;
//}
