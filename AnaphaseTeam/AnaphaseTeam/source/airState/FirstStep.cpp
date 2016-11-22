/**
* @file firstStep.cpp
* @brief 一段ジャンプ目のステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#include "../../header/airstate/firstStep.h"
#include "../../header/airstate/secondStep.h"
#include "../../header/airstate/RestrictionFall.h"
#include "../../header/airstate/GroundState.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/math/Calculate.h"
#include "../../header/subAction/JumpControl.h"

#include "../../header/actionstate/AvoidState.h"
const float FirstStep::FirstStepPow = 0.6f;

FirstStep::FirstStep(JumpControl* _control, Player* _player)
	:m_isEnd(false),
	m_control(_control),
	m_player(_player)
{

}

FirstStep::~FirstStep()
{

}
/**
* @fn
* @brief ステート変更時のジャンプ力の設定
*/
void FirstStep::start()
{
	m_isEnd = false;
	m_player->startJump(m_control, FirstStepPow);
}
/**
* @fn
* @brief ジャンプ一段目の行動
*/
void FirstStep::update(float deltaTime)
{
	m_player->jumpMotion(*m_control, ANIMATION_ID::STAND);
	m_player->moving(deltaTime, false);
	m_player->control();
	m_control->jumping(deltaTime, m_player);
	change();
}

const bool FirstStep::isEnd() const
{
	return m_isEnd;
}

std::shared_ptr<IAirState> FirstStep::next() const
{
	return m_next;
}

void FirstStep::change()
{
	if (m_player->isGround())
	{
		m_isEnd = true;
		m_next = std::make_shared<GroundState>(m_control, m_player);
	}

	if (m_player->isJump())
	{
		m_isEnd = true;
		m_next = std::make_shared<SecondStep>(m_control, m_player);
	}
}
