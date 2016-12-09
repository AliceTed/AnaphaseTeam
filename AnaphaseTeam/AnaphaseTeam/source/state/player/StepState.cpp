#include"../../../header/state/player/StepState.h"
#include "../../../header/data/id/ANIMATION_ID.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/math/Calculate.h"
Player::StepState::StepState(Player* _player)
	:ActorState(_player),
	m_step(_player),
	m_velocity(4.5f)
{
}

void Player::StepState::start()
{
	m_actor->m_animatorOne.changeAnimation(static_cast<GSuint>(ANIMATION_ID::STAND), true);
	m_velocity = 4.5f;
	if (m_actor->m_isLockOn)
	{
		//Math::Clamp clamp;
		//m_velocity = clamp(m_velocity, 0.0f, m_actor->stepDistance());
		m_actor->lookTarget();
		m_velocity = m_actor->stepDistance();
	}
	if (m_velocity <= 1.0f)
	{
		changeState(ACTOR_STATE::STAND);
		return;
	}
	if (!m_actor->m_Gauge->down(5))
	{
		return;
	}
	m_step.start(m_actor->m_transform.front(), m_velocity);
}
void Player::StepState::action(float deltaTime)
{
	m_step.update(deltaTime);
	if (m_step.isEnd())
	{
		changeState(ACTOR_STATE::STAND);
	}
}
Player::StepState* Player::StepState::clone() const
{
	return new StepState(*this);
}