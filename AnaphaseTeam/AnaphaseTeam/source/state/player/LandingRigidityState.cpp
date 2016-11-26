#include"../../../header/state/player/LandingRigidityState.h"
#include "../../../header/data/ANIMATION_ID.h"
Player::LandingRigidityState::LandingRigidityState(Player* _player)
	:ActorState(_player),
	m_timer(0.6f)
{
}

void Player::LandingRigidityState::start()
{
	m_actor->m_animatorOne.changeAnimation(static_cast<GSuint>(ANIMATION_ID::STAND), false);
	m_timer.initialize();
}
void Player::LandingRigidityState::action(float deltaTime)
{
	m_actor->control();
	m_timer.update(deltaTime);
	if (m_timer.isEnd())
	{
		changeState(ACTOR_STATE::STAND);
	}
}
Player::LandingRigidityState* Player::LandingRigidityState::clone() const
{
	return new LandingRigidityState(*this);
}