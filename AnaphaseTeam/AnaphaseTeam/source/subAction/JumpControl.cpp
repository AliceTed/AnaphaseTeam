/**
* @file jumpControl.cpp
* @brief ジャンプの制御
* @author 渋谷知樹
* @date 2016/08/29
*/
#include "../../header/subaction/jumpControl.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/math/Calculate.h"
#include "../../header/airstate/PreparationState.h"

const float JumpControl::Acceleration = 0.05f;
const float JumpControl::MaxJumpPower = 2.0f;
JumpControl::JumpControl(Player* _player)
	:m_airAction(nullptr),
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
	AirAction_Ptr action = std::make_shared<PreparationState>(this, m_player);
	change(action);
}

void JumpControl::update(float deltaTime)
{
	m_airAction->update(deltaTime);
	airActionChange();
}

/**
* @fn
* @brief アニメーションの変更（ジャンプ）
*/
void JumpControl::changeMotion(AnimatorOne & _animator, ANIMATION_ID _id, float _animSpeed)
{
	_animator.changeAnimationLerp(_id);
	//_animator.lerpBegin(_id, true, false);
}
/**
* @fn
* @brief ジャンプ時のステート切り替え
*/
void JumpControl::airActionChange()
{
	if (!m_airAction->isEnd()) {
		return;
	}
	AirAction_Ptr next = m_airAction->next();
	if (next == nullptr)//!next
	{
		m_isEnd = true;
		return;
	}
	change(next);
}

void JumpControl::change(AirAction_Ptr _next)
{
	m_airAction = _next;
	m_airAction->start();
}

const bool JumpControl::isEnd() const
{
	return m_isEnd;
}

void JumpControl::setPower(float _power)
{
	m_JumpPower = _power;
}

/**
* @fn
* @brief プレイヤーのｙ方向の移動
*/
void JumpControl::jumping(float deltaTime, Player * _player)
{
	_player->jumping(m_JumpPower*deltaTime);
	Math::Clamp clamp;
	m_JumpPower = clamp(m_JumpPower - Acceleration, -MaxJumpPower, MaxJumpPower);
}
