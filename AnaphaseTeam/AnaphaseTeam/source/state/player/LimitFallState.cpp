#include"state/player/LimitFallState.h"
#include "data/id/ANIMATION_ID.h"
Player::LimitFallState::LimitFallState(Player* _player)
	:ActorState(_player),
	m_jumping(_player)
{
}

void Player::LimitFallState::start()
{
	m_actor->m_animatorOne.changeAnimation(static_cast<GSuint>(ANIMATION_ID::STAND), false);
	m_jumping.start(0);
}
void Player::LimitFallState::action(float deltaTime)
{
	float speed = 0.05f;
	m_actor->movement(deltaTime, speed);
	m_jumping.update(deltaTime);
	if (m_actor->m_isGround)
	{
		changeState(ACTOR_STATE::LANDINGRIGIDITY);
	}
}
Player::LimitFallState* Player::LimitFallState::clone() const
{
	return new LimitFallState(*this);
}