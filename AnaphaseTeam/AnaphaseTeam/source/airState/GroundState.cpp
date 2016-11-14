/**
* @file groundState.cpp
* @brief 着地のステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#include "../../header/airstate/groundState.h"
#include "../../header/airstate/PreparationState.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/subAction/JumpControl.h"
const float GroundState::ANIMSPEED = 1.5f;
GroundState::GroundState(JumpControl* _control, Player* _player)
	:m_isEnd(false),
	m_control(_control),
	m_player(_player),m_timer(0.0f)
{

}
GroundState::~GroundState()
{

}
void GroundState::start()
{
	m_isEnd = false;
	m_timer = 0.f;
}
/**
* @fn
* @brief ジャンプ後の着地時の行動
*/
void GroundState::update(float deltaTime)
{
	m_player->moveStart();
	m_player->control();
	//m_player->subActionStart();
	m_player->jumpMotion(*m_control, ANIMATION_ID::STAND, ANIMSPEED);
	m_timer += deltaTime*0.1f;
	if (m_timer>1.0f)
	{
		m_isEnd = true;
	}
}

const bool GroundState::isEnd() const
{
	return m_isEnd;
}

std::shared_ptr<IAirState> GroundState::next() const
{
	return nullptr;
}