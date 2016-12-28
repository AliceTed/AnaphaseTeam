#include "../../../header/state/player/HomingState.h"
#include "../../../header/data/id/ANIMATION_ID.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/math/Calculate.h"
Player::HomingState::HomingState(Player* _player)
	:ActorState(_player),
	m_step(_player),
	m_velocity(0.0f)
{
}

void Player::HomingState::start()
{
	m_actor->m_animatorOne.changeAnimation(ANIMATION_ID::ATTACK1);
	GameDevice::getInstacnce().sound().playSE(SE_ID::PLAYER_STEP);
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
void Player::HomingState::action(float deltaTime)
{
	m_step.update(deltaTime);
	if (m_step.isEnd())
	{
		GameDevice::getInstacnce().sound().stopSE(SE_ID::PLAYER_STEP);
		changeState(ACTOR_STATE::STAND);
	}
}
Player::HomingState* Player::HomingState::clone() const
{
	return new HomingState(*this);
}

void Player::HomingState::tracking()
{
	m_actor->lookTarget();
	m_velocity = m_actor->stepDistance();
}