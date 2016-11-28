/**
* @file secondStep.cpp
* @brief 二段ジャンプ目のステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#include "../../header/airstate/SecondStep.h"
#include "../../header/airstate/RestrictionFall.h"
#include "../../header/airstate/GroundState.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/math/Calculate.h"
#include "../../header/subAction/JumpControl.h"
const float SecondStep::SecondStepPow = 0.6f;
SecondStep::SecondStep(JumpControl* _control, Player* _player)
	:m_isEnd(false),
	m_control(_control),
	m_player(_player)
{

}
SecondStep::~SecondStep()
{

}
void SecondStep::start()
{
	m_isEnd = false;
	m_player->startJump(m_control, SecondStepPow);
}
void SecondStep::update(float deltaTime)
{
	m_player->jumpMotion(*m_control,ANIMATION_ID::STAND);
	m_player->moving(deltaTime,false);
	m_player->control();
	m_control->jumping(deltaTime, m_player);
	change();
}

const bool SecondStep::isEnd() const
{
	return m_isEnd;
}

std::shared_ptr<IAirState> SecondStep::next() const
{
	return m_next;
}

void SecondStep::change()
{
	if (m_player->isGround())
	{
		m_isEnd = true;
		m_next = std::make_shared<GroundState>(m_control, m_player);
	}
}

