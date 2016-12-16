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
	GameDevice::getInstacnce().sound().playSE(SE_ID::PLAYER_STEP);
	m_velocity = 4.5f;
	tracking();
	if (m_velocity <= 1.0f)
	{
		changeState(ACTOR_STATE::STAND);
		return;
	}
	if (!m_actor->m_Gauge->down(5))
	{
		changeState(ACTOR_STATE::STAND);
		return;
	}
	if (m_actor->aerialTracking())
	{
		m_velocity += 2;
		m_step.start(m_actor->m_transform.up(), m_velocity);
		return;
	}
	m_step.start(m_actor->m_transform.front(), m_velocity);
}
void Player::StepState::action(float deltaTime)
{
	m_step.update(deltaTime);
	if (m_step.isEnd())
	{
		GameDevice::getInstacnce().sound().stopSE(SE_ID::PLAYER_STEP);
		changeState(ACTOR_STATE::STAND);
	}
}
Player::StepState* Player::StepState::clone() const
{
	return new StepState(*this);
}

void Player::StepState::tracking()
{
	if (m_actor->m_isLockOn)
	{
		m_actor->lookTarget();
		m_velocity = m_actor->stepDistance();
	}
}
