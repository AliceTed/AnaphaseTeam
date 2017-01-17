#include"state/player/StepState.h"
#include "data/id/ANIMATION_ID.h"
#include "device/GameDevice.h"
#include "math/Calculate.h"
Player::StepState::StepState(Player* _player)
	:ActorState(_player),
	m_step(_player),
	m_velocity(4.5f)
{
}

void Player::StepState::start()
{
	m_actor->m_animatorOne.changeAnimation(ANIMATION_ID::STEP);
	GameDevice::getInstacnce().sound().playSE(SE_ID::PLAYER_STEP);
	m_velocity = 4.5f;
	if (!m_actor->m_Gauge->down(5))
	{
		changeState(ACTOR_STATE::STAND);
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
