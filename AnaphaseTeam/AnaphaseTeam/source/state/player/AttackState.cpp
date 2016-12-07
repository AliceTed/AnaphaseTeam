#include "../../../header/state/player/AttackState.h"
#include "../../../header/data/id/ANIMATION_ID.h"
#include "../../../header/device/GameDevice.h"

Player::AttackState::AttackState(Player* _player)
	:ActorState(_player),
	m_inputTimer(0.17f)
{
}

void Player::AttackState::start()
{
	m_inputTimer.initialize();
}
void Player::AttackState::action(float deltaTime)
{
	m_actor->m_combo.update(deltaTime);
	input(deltaTime);
	m_actor->m_homing.update(deltaTime, &m_actor->m_transform.m_translate);
}
Player::AttackState* Player::AttackState::clone() const
{
	return new AttackState(*this);
}

void Player::AttackState::input(float deltaTime)
{
	if (!m_actor->m_animatorOne.isEndCurrentAnimation())return;
//	m_actor->m_animatorOne.changeAnimationLerp(static_cast<GSuint>(ANIMATION_ID::STAND));
	m_inputTimer.update(deltaTime);

	if (m_inputTimer.isEnd())
	{
		changeState(ACTOR_STATE::STAND);
		return;
	}
	Input_Ptr& input = GameDevice::getInstacnce().input();
	bool isSlow = input->slowAttackTrigger();
	if (!input->quickAttackTrigger() && !isSlow)return;
	m_inputTimer.initialize();
	//
	if (m_actor->m_combo.next(isSlow))return;
	changeState(ACTOR_STATE::STAND);
}
